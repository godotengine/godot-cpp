#pragma once

#include <core/Godot.hpp>
#include <core/String.hpp>
#include <EditorPlugin.hpp>
#include <ResourceLoader.hpp>
#include <Script.hpp>
#include <Texture.hpp>

namespace godot {
    namespace plugins {
        template<
                class NodeClass,
                const std::string& nodeHierarchyParent,
                const std::string& gdnsScriptPath
        >
        class NodeWrapper : public godot::GodotScript<godot::EditorPlugin> {
            // had to replace GODOT_CLASS macro to gen wrapper name on the fly
        public:
            inline static const char* ___get_type_name() {
                godot::String wrapperName(NodeClass::___get_type_name());
                wrapperName += "NodeWrapper";
                return wrapperName.alloc_c_string();
            }

        public:
            NodeWrapper() = default;

            ~NodeWrapper() = default;

            void _enter_tree() {
                godot::Ref<godot::Script> script = godot::ResourceLoader::load(gdnsScriptPath.c_str());
                owner->add_custom_type(NodeClass::___get_type_name(), nodeHierarchyParent.c_str(), script,
                                       godot::Ref<godot::Texture>());

                godot::String msg("Enabled custom node ");
                msg += NodeClass::___get_type_name();
                godot::Godot::print(msg);
            }

            void _exit_tree() {
                owner->remove_custom_type(NodeClass::___get_type_name());

                godot::String msg("Disabled custom node ");
                msg += NodeClass::___get_type_name();
                godot::Godot::print(msg);
            }

            [[maybe_unused]]
            static void _register_methods() {
                godot::register_method("_enter_tree", &NodeWrapper::_enter_tree);
                godot::register_method("_exit_tree", &NodeWrapper::_exit_tree);
            }
        };

#define NODE_WRAPPER(NodeClass, NodeHierarchyParent, GdnsPath) \
    const std::string NodeClass##LibraryPath(GdnsPath); \
    const std::string NodeClass##HierarchyParent(#NodeHierarchyParent); \
    using NodeClass##NodeWrapper = godot::plugins::NodeWrapper<NodeClass, NodeClass##HierarchyParent, NodeClass##LibraryPath>;
    }
}