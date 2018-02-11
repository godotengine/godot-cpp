#include "TagDB.hpp"

#include <GlobalConstants.hpp>
#include <Object.hpp>
#include <Reference.hpp>
#include <Resource.hpp>
#include <Script.hpp>
#include <WeakRef.hpp>
#include <Image.hpp>
#include <InputEvent.hpp>
#include <InputEventWithModifiers.hpp>
#include <InputEventKey.hpp>
#include <InputEventMouse.hpp>
#include <InputEventMouseButton.hpp>
#include <InputEventMouseMotion.hpp>
#include <InputEventJoypadButton.hpp>
#include <InputEventJoypadMotion.hpp>
#include <InputEventScreenDrag.hpp>
#include <InputEventScreenTouch.hpp>
#include <InputEventAction.hpp>
#include <InputEventGesture.hpp>
#include <InputEventMagnifyGesture.hpp>
#include <InputEventPanGesture.hpp>
#include <FuncRef.hpp>
#include <StreamPeer.hpp>
#include <StreamPeerBuffer.hpp>
#include <StreamPeerTCP.hpp>
#include <TCP_Server.hpp>
#include <PacketPeer.hpp>
#include <PacketPeerUDP.hpp>
#include <StreamPeerSSL.hpp>
#include <IP.hpp>
#include <PacketPeerStream.hpp>
#include <NetworkedMultiplayerPeer.hpp>
#include <MainLoop.hpp>
#include <Translation.hpp>
#include <PHashTranslation.hpp>
#include <UndoRedo.hpp>
#include <HTTPClient.hpp>
#include <TriangleMesh.hpp>
#include <ResourceInteractiveLoader.hpp>
#include <File.hpp>
#include <Directory.hpp>
#include <Thread.hpp>
#include <Mutex.hpp>
#include <Semaphore.hpp>
#include <XMLParser.hpp>
#include <ConfigFile.hpp>
#include <PCKPacker.hpp>
#include <PackedDataContainer.hpp>
#include <PackedDataContainerRef.hpp>
#include <AStar.hpp>
#include <EncodedObjectAsID.hpp>
#include <JSONParseResult.hpp>
#include <IP_Unix.hpp>
#include <Geometry.hpp>
#include <ResourceLoader.hpp>
#include <ResourceSaver.hpp>
#include <OS.hpp>
#include <Engine.hpp>
#include <ClassDB.hpp>
#include <Marshalls.hpp>
#include <JSON.hpp>
#include <ProjectSettings.hpp>
#include <InputMap.hpp>
#include <TranslationServer.hpp>
#include <Performance.hpp>
#include <VisualServer.hpp>
#include <InputDefault.hpp>
#include <Input.hpp>
#include <AudioServer.hpp>
#include <ARVRServer.hpp>
#include <PhysicsServer.hpp>
#include <Physics2DServer.hpp>
#include <ARVRInterface.hpp>
#include <ARVRPositionalTracker.hpp>
#include <AudioStream.hpp>
#include <AudioStreamPlayback.hpp>
#include <AudioStreamRandomPitch.hpp>
#include <AudioEffect.hpp>
#include <AudioEffectEQ.hpp>
#include <AudioEffectFilter.hpp>
#include <AudioBusLayout.hpp>
#include <AudioEffectAmplify.hpp>
#include <AudioEffectReverb.hpp>
#include <AudioEffectLowPassFilter.hpp>
#include <AudioEffectHighPassFilter.hpp>
#include <AudioEffectBandPassFilter.hpp>
#include <AudioEffectNotchFilter.hpp>
#include <AudioEffectBandLimitFilter.hpp>
#include <AudioEffectLowShelfFilter.hpp>
#include <AudioEffectHighShelfFilter.hpp>
#include <AudioEffectEQ6.hpp>
#include <AudioEffectEQ10.hpp>
#include <AudioEffectEQ21.hpp>
#include <AudioEffectDistortion.hpp>
#include <AudioEffectStereoEnhance.hpp>
#include <AudioEffectPanner.hpp>
#include <AudioEffectChorus.hpp>
#include <AudioEffectDelay.hpp>
#include <AudioEffectCompressor.hpp>
#include <AudioEffectLimiter.hpp>
#include <AudioEffectPitchShift.hpp>
#include <AudioEffectPhaser.hpp>
#include <Physics2DDirectBodyState.hpp>
#include <Physics2DDirectSpaceState.hpp>
#include <Physics2DShapeQueryResult.hpp>
#include <Physics2DTestMotionResult.hpp>
#include <Physics2DShapeQueryParameters.hpp>
#include <PhysicsShapeQueryParameters.hpp>
#include <PhysicsDirectBodyState.hpp>
#include <PhysicsDirectSpaceState.hpp>
#include <PhysicsShapeQueryResult.hpp>
#include <CanvasModulate.hpp>
#include <ResourcePreloader.hpp>
#include <ButtonGroup.hpp>
#include <Control.hpp>
#include <InstancePlaceholder.hpp>
#include <Viewport.hpp>
#include <Node.hpp>
#include <ColorRect.hpp>
#include <NinePatchRect.hpp>
#include <TabContainer.hpp>
#include <Tabs.hpp>
#include <CanvasLayer.hpp>
#include <Texture.hpp>
#include <World.hpp>
#include <World2D.hpp>
#include <BaseButton.hpp>
#include <Label.hpp>
#include <Range.hpp>
#include <CanvasItem.hpp>
#include <ShortCut.hpp>
#include <Button.hpp>
#include <ViewportTexture.hpp>
#include <HTTPRequest.hpp>
#include <VBoxContainer.hpp>
#include <GridContainer.hpp>
#include <CenterContainer.hpp>
#include <ScrollContainer.hpp>
#include <PanelContainer.hpp>
#include <SplitContainer.hpp>
#include <VSplitContainer.hpp>
#include <GraphNode.hpp>
#include <GraphEdit.hpp>
#include <Node2D.hpp>
#include <ScrollBar.hpp>
#include <HScrollBar.hpp>
#include <VScrollBar.hpp>
#include <ProgressBar.hpp>
#include <Slider.hpp>
#include <HSlider.hpp>
#include <VSlider.hpp>
#include <Popup.hpp>
#include <PopupPanel.hpp>
#include <MenuButton.hpp>
#include <CheckBox.hpp>
#include <CheckButton.hpp>
#include <ToolButton.hpp>
#include <LinkButton.hpp>
#include <Panel.hpp>
#include <TextureRect.hpp>
#include <TextureProgress.hpp>
#include <ItemList.hpp>
#include <WindowDialog.hpp>
#include <AcceptDialog.hpp>
#include <Separator.hpp>
#include <HSeparator.hpp>
#include <VSeparator.hpp>
#include <TextureButton.hpp>
#include <BitMap.hpp>
#include <Container.hpp>
#include <BoxContainer.hpp>
#include <HBoxContainer.hpp>
#include <HSplitContainer.hpp>
#include <Theme.hpp>
#include <Timer.hpp>
#include <ConfirmationDialog.hpp>
#include <FileDialog.hpp>
#include <LineEdit.hpp>
#include <PopupMenu.hpp>
#include <Tree.hpp>
#include <TextEdit.hpp>
#include <TreeItem.hpp>
#include <OptionButton.hpp>
#include <SpinBox.hpp>
#include <ReferenceRect.hpp>
#include <ColorPicker.hpp>
#include <ColorPickerButton.hpp>
#include <RichTextLabel.hpp>
#include <PopupDialog.hpp>
#include <VideoPlayer.hpp>
#include <VideoStream.hpp>
#include <MarginContainer.hpp>
#include <ViewportContainer.hpp>
#include <Spatial.hpp>
#include <SpatialGizmo.hpp>
#include <Skeleton.hpp>
#include <AnimationPlayer.hpp>
#include <Tween.hpp>
#include <BoneAttachment.hpp>
#include <VisualInstance.hpp>
#include <GeometryInstance.hpp>
#include <Camera.hpp>
#include <Environment.hpp>
#include <Listener.hpp>
#include <ARVRCamera.hpp>
#include <ARVRController.hpp>
#include <ARVRAnchor.hpp>
#include <ARVROrigin.hpp>
#include <InterpolatedCamera.hpp>
#include <MeshInstance.hpp>
#include <Mesh.hpp>
#include <ImmediateGeometry.hpp>
#include <SpriteBase3D.hpp>
#include <Sprite3D.hpp>
#include <AnimatedSprite3D.hpp>
#include <SpriteFrames.hpp>
#include <Light.hpp>
#include <DirectionalLight.hpp>
#include <OmniLight.hpp>
#include <SpotLight.hpp>
#include <ReflectionProbe.hpp>
#include <GIProbe.hpp>
#include <GIProbeData.hpp>
#include <BakedLightmap.hpp>
#include <BakedLightmapData.hpp>
#include <AnimationTreePlayer.hpp>
#include <Particles.hpp>
#include <Position3D.hpp>
#include <NavigationMeshInstance.hpp>
#include <NavigationMesh.hpp>
#include <Navigation.hpp>
#include <CollisionObject.hpp>
#include <PhysicsBody.hpp>
#include <StaticBody.hpp>
#include <RigidBody.hpp>
#include <KinematicCollision.hpp>
#include <KinematicBody.hpp>
#include <VehicleBody.hpp>
#include <VehicleWheel.hpp>
#include <Area.hpp>
#include <ProximityGroup.hpp>
#include <CollisionShape.hpp>
#include <Shape.hpp>
#include <CollisionPolygon.hpp>
#include <RayCast.hpp>
#include <MultiMeshInstance.hpp>
#include <MultiMesh.hpp>
#include <Curve3D.hpp>
#include <Path.hpp>
#include <PathFollow.hpp>
#include <VisibilityNotifier.hpp>
#include <VisibilityEnabler.hpp>
#include <WorldEnvironment.hpp>
#include <RemoteTransform.hpp>
#include <Joint.hpp>
#include <PinJoint.hpp>
#include <HingeJoint.hpp>
#include <SliderJoint.hpp>
#include <ConeTwistJoint.hpp>
#include <Generic6DOFJoint.hpp>
#include <MeshLibrary.hpp>
#include <Shader.hpp>
#include <Material.hpp>
#include <ShaderMaterial.hpp>
#include <CanvasItemMaterial.hpp>
#include <Particles2D.hpp>
#include <Sprite.hpp>
#include <AnimatedSprite.hpp>
#include <Position2D.hpp>
#include <Line2D.hpp>
#include <Gradient.hpp>
#include <MeshInstance2D.hpp>
#include <CollisionObject2D.hpp>
#include <PhysicsBody2D.hpp>
#include <StaticBody2D.hpp>
#include <RigidBody2D.hpp>
#include <KinematicBody2D.hpp>
#include <KinematicCollision2D.hpp>
#include <Area2D.hpp>
#include <CollisionShape2D.hpp>
#include <Shape2D.hpp>
#include <CollisionPolygon2D.hpp>
#include <RayCast2D.hpp>
#include <VisibilityNotifier2D.hpp>
#include <VisibilityEnabler2D.hpp>
#include <Polygon2D.hpp>
#include <Light2D.hpp>
#include <LightOccluder2D.hpp>
#include <OccluderPolygon2D.hpp>
#include <YSort.hpp>
#include <BackBufferCopy.hpp>
#include <Camera2D.hpp>
#include <Joint2D.hpp>
#include <PinJoint2D.hpp>
#include <GrooveJoint2D.hpp>
#include <DampedSpringJoint2D.hpp>
#include <TileSet.hpp>
#include <TileMap.hpp>
#include <ParallaxBackground.hpp>
#include <ParallaxLayer.hpp>
#include <TouchScreenButton.hpp>
#include <RemoteTransform2D.hpp>
#include <ArrayMesh.hpp>
#include <PrimitiveMesh.hpp>
#include <CapsuleMesh.hpp>
#include <CubeMesh.hpp>
#include <CylinderMesh.hpp>
#include <PlaneMesh.hpp>
#include <PrismMesh.hpp>
#include <QuadMesh.hpp>
#include <SphereMesh.hpp>
#include <SpatialMaterial.hpp>
#include <ParticlesMaterial.hpp>
#include <CurveTexture.hpp>
#include <GradientTexture.hpp>
#include <RayShape.hpp>
#include <SphereShape.hpp>
#include <BoxShape.hpp>
#include <CapsuleShape.hpp>
#include <PlaneShape.hpp>
#include <ConvexPolygonShape.hpp>
#include <ConcavePolygonShape.hpp>
#include <SurfaceTool.hpp>
#include <MeshDataTool.hpp>
#include <SpatialVelocityTracker.hpp>
#include <Sky.hpp>
#include <PanoramaSky.hpp>
#include <ProceduralSky.hpp>
#include <StreamTexture.hpp>
#include <ImageTexture.hpp>
#include <AtlasTexture.hpp>
#include <LargeTexture.hpp>
#include <Curve.hpp>
#include <ProxyTexture.hpp>
#include <CubeMap.hpp>
#include <Animation.hpp>
#include <Font.hpp>
#include <BitmapFont.hpp>
#include <DynamicFontData.hpp>
#include <DynamicFont.hpp>
#include <StyleBox.hpp>
#include <StyleBoxEmpty.hpp>
#include <StyleBoxTexture.hpp>
#include <StyleBoxFlat.hpp>
#include <StyleBoxLine.hpp>
#include <PolygonPathFinder.hpp>
#include <AudioStreamPlayer.hpp>
#include <AudioStreamPlayer2D.hpp>
#include <AudioStreamPlayer3D.hpp>
#include <AudioStreamSample.hpp>
#include <LineShape2D.hpp>
#include <SegmentShape2D.hpp>
#include <RayShape2D.hpp>
#include <CircleShape2D.hpp>
#include <RectangleShape2D.hpp>
#include <CapsuleShape2D.hpp>
#include <ConvexPolygonShape2D.hpp>
#include <ConcavePolygonShape2D.hpp>
#include <Curve2D.hpp>
#include <Path2D.hpp>
#include <PathFollow2D.hpp>
#include <Navigation2D.hpp>
#include <NavigationPolygon.hpp>
#include <NavigationPolygonInstance.hpp>
#include <SceneState.hpp>
#include <PackedScene.hpp>
#include <SceneTree.hpp>
#include <SceneTreeTimer.hpp>
#include <EditorPlugin.hpp>
#include <EditorImportPlugin.hpp>
#include <EditorScript.hpp>
#include <EditorSelection.hpp>
#include <EditorFileDialog.hpp>
#include <EditorSettings.hpp>
#include <EditorSpatialGizmo.hpp>
#include <EditorResourcePreview.hpp>
#include <EditorResourcePreviewGenerator.hpp>
#include <EditorFileSystem.hpp>
#include <EditorFileSystemDirectory.hpp>
#include <ScriptEditor.hpp>
#include <EditorInterface.hpp>
#include <EditorExportPlugin.hpp>
#include <EditorResourceConversionPlugin.hpp>
#include <EditorSceneImporter.hpp>
#include <EditorScenePostImport.hpp>
#include <JavaScript.hpp>
#include <NetworkedMultiplayerENet.hpp>
#include <GDNativeLibrary.hpp>
#include <GDNative.hpp>
#include <ARVRInterfaceGDNative.hpp>
#include <NativeScript.hpp>
#include <PluginScript.hpp>
#include <GDScript.hpp>
#include <GDScriptFunctionState.hpp>
#include <GridMap.hpp>
#include <RegExMatch.hpp>
#include <RegEx.hpp>
#include <ResourceImporterOGGVorbis.hpp>
#include <ResourceImporter.hpp>
#include <AudioStreamOGGVorbis.hpp>
#include <ResourceImporterTheora.hpp>
#include <VideoStreamTheora.hpp>
#include <VisualScript.hpp>
#include <VisualScriptNode.hpp>
#include <VisualScriptFunctionState.hpp>
#include <VisualScriptFunction.hpp>
#include <VisualScriptOperator.hpp>
#include <VisualScriptVariableSet.hpp>
#include <VisualScriptVariableGet.hpp>
#include <VisualScriptConstant.hpp>
#include <VisualScriptIndexGet.hpp>
#include <VisualScriptIndexSet.hpp>
#include <VisualScriptGlobalConstant.hpp>
#include <VisualScriptClassConstant.hpp>
#include <VisualScriptMathConstant.hpp>
#include <VisualScriptBasicTypeConstant.hpp>
#include <VisualScriptEngineSingleton.hpp>
#include <VisualScriptSceneNode.hpp>
#include <VisualScriptSceneTree.hpp>
#include <VisualScriptResourcePath.hpp>
#include <VisualScriptSelf.hpp>
#include <VisualScriptCustomNode.hpp>
#include <VisualScriptSubCall.hpp>
#include <VisualScriptComment.hpp>
#include <VisualScriptConstructor.hpp>
#include <VisualScriptLocalVar.hpp>
#include <VisualScriptLocalVarSet.hpp>
#include <VisualScriptInputAction.hpp>
#include <VisualScriptDeconstruct.hpp>
#include <VisualScriptPreload.hpp>
#include <VisualScriptTypeCast.hpp>
#include <VisualScriptFunctionCall.hpp>
#include <VisualScriptPropertySet.hpp>
#include <VisualScriptPropertyGet.hpp>
#include <VisualScriptEmitSignal.hpp>
#include <VisualScriptReturn.hpp>
#include <VisualScriptCondition.hpp>
#include <VisualScriptWhile.hpp>
#include <VisualScriptIterator.hpp>
#include <VisualScriptSequence.hpp>
#include <VisualScriptSwitch.hpp>
#include <VisualScriptSelect.hpp>
#include <VisualScriptYield.hpp>
#include <VisualScriptYieldSignal.hpp>
#include <VisualScriptBuiltinFunc.hpp>
#include <VisualScriptExpression.hpp>
#include <WebSocketMultiplayerPeer.hpp>
#include <ResourceImporterWebm.hpp>
#include <VideoStreamWebm.hpp>
#include <VisualScriptEditor.hpp>
#include <WebSocketServer.hpp>
#include <WebSocketClient.hpp>
#include <WebSocketPeer.hpp>
#include <BulletPhysicsServer.hpp>
#include <BulletPhysicsDirectBodyState.hpp>
#include <Physics2DServerSW.hpp>
#include <Physics2DDirectBodyStateSW.hpp>


namespace godot {
void ___register_types()
{
	godot::_TagDB::register_global_type("GlobalConstants", GlobalConstants::___get_type_tag(), GlobalConstants::___get_base_type_tag());
	godot::_TagDB::register_global_type("Object", Object::___get_type_tag(), Object::___get_base_type_tag());
	godot::_TagDB::register_global_type("Reference", Reference::___get_type_tag(), Reference::___get_base_type_tag());
	godot::_TagDB::register_global_type("Resource", Resource::___get_type_tag(), Resource::___get_base_type_tag());
	godot::_TagDB::register_global_type("Script", Script::___get_type_tag(), Script::___get_base_type_tag());
	godot::_TagDB::register_global_type("WeakRef", WeakRef::___get_type_tag(), WeakRef::___get_base_type_tag());
	godot::_TagDB::register_global_type("Image", Image::___get_type_tag(), Image::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEvent", InputEvent::___get_type_tag(), InputEvent::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventWithModifiers", InputEventWithModifiers::___get_type_tag(), InputEventWithModifiers::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventKey", InputEventKey::___get_type_tag(), InputEventKey::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventMouse", InputEventMouse::___get_type_tag(), InputEventMouse::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventMouseButton", InputEventMouseButton::___get_type_tag(), InputEventMouseButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventMouseMotion", InputEventMouseMotion::___get_type_tag(), InputEventMouseMotion::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventJoypadButton", InputEventJoypadButton::___get_type_tag(), InputEventJoypadButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventJoypadMotion", InputEventJoypadMotion::___get_type_tag(), InputEventJoypadMotion::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventScreenDrag", InputEventScreenDrag::___get_type_tag(), InputEventScreenDrag::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventScreenTouch", InputEventScreenTouch::___get_type_tag(), InputEventScreenTouch::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventAction", InputEventAction::___get_type_tag(), InputEventAction::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventGesture", InputEventGesture::___get_type_tag(), InputEventGesture::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventMagnifyGesture", InputEventMagnifyGesture::___get_type_tag(), InputEventMagnifyGesture::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputEventPanGesture", InputEventPanGesture::___get_type_tag(), InputEventPanGesture::___get_base_type_tag());
	godot::_TagDB::register_global_type("FuncRef", FuncRef::___get_type_tag(), FuncRef::___get_base_type_tag());
	godot::_TagDB::register_global_type("StreamPeer", StreamPeer::___get_type_tag(), StreamPeer::___get_base_type_tag());
	godot::_TagDB::register_global_type("StreamPeerBuffer", StreamPeerBuffer::___get_type_tag(), StreamPeerBuffer::___get_base_type_tag());
	godot::_TagDB::register_global_type("StreamPeerTCP", StreamPeerTCP::___get_type_tag(), StreamPeerTCP::___get_base_type_tag());
	godot::_TagDB::register_global_type("TCP_Server", TCP_Server::___get_type_tag(), TCP_Server::___get_base_type_tag());
	godot::_TagDB::register_global_type("PacketPeer", PacketPeer::___get_type_tag(), PacketPeer::___get_base_type_tag());
	godot::_TagDB::register_global_type("PacketPeerUDP", PacketPeerUDP::___get_type_tag(), PacketPeerUDP::___get_base_type_tag());
	godot::_TagDB::register_global_type("StreamPeerSSL", StreamPeerSSL::___get_type_tag(), StreamPeerSSL::___get_base_type_tag());
	godot::_TagDB::register_global_type("IP", IP::___get_type_tag(), IP::___get_base_type_tag());
	godot::_TagDB::register_global_type("PacketPeerStream", PacketPeerStream::___get_type_tag(), PacketPeerStream::___get_base_type_tag());
	godot::_TagDB::register_global_type("NetworkedMultiplayerPeer", NetworkedMultiplayerPeer::___get_type_tag(), NetworkedMultiplayerPeer::___get_base_type_tag());
	godot::_TagDB::register_global_type("MainLoop", MainLoop::___get_type_tag(), MainLoop::___get_base_type_tag());
	godot::_TagDB::register_global_type("Translation", Translation::___get_type_tag(), Translation::___get_base_type_tag());
	godot::_TagDB::register_global_type("PHashTranslation", PHashTranslation::___get_type_tag(), PHashTranslation::___get_base_type_tag());
	godot::_TagDB::register_global_type("UndoRedo", UndoRedo::___get_type_tag(), UndoRedo::___get_base_type_tag());
	godot::_TagDB::register_global_type("HTTPClient", HTTPClient::___get_type_tag(), HTTPClient::___get_base_type_tag());
	godot::_TagDB::register_global_type("TriangleMesh", TriangleMesh::___get_type_tag(), TriangleMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("ResourceInteractiveLoader", ResourceInteractiveLoader::___get_type_tag(), ResourceInteractiveLoader::___get_base_type_tag());
	godot::_TagDB::register_global_type("File", File::___get_type_tag(), File::___get_base_type_tag());
	godot::_TagDB::register_global_type("Directory", Directory::___get_type_tag(), Directory::___get_base_type_tag());
	godot::_TagDB::register_global_type("Thread", Thread::___get_type_tag(), Thread::___get_base_type_tag());
	godot::_TagDB::register_global_type("Mutex", Mutex::___get_type_tag(), Mutex::___get_base_type_tag());
	godot::_TagDB::register_global_type("Semaphore", Semaphore::___get_type_tag(), Semaphore::___get_base_type_tag());
	godot::_TagDB::register_global_type("XMLParser", XMLParser::___get_type_tag(), XMLParser::___get_base_type_tag());
	godot::_TagDB::register_global_type("ConfigFile", ConfigFile::___get_type_tag(), ConfigFile::___get_base_type_tag());
	godot::_TagDB::register_global_type("PCKPacker", PCKPacker::___get_type_tag(), PCKPacker::___get_base_type_tag());
	godot::_TagDB::register_global_type("PackedDataContainer", PackedDataContainer::___get_type_tag(), PackedDataContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("PackedDataContainerRef", PackedDataContainerRef::___get_type_tag(), PackedDataContainerRef::___get_base_type_tag());
	godot::_TagDB::register_global_type("AStar", AStar::___get_type_tag(), AStar::___get_base_type_tag());
	godot::_TagDB::register_global_type("EncodedObjectAsID", EncodedObjectAsID::___get_type_tag(), EncodedObjectAsID::___get_base_type_tag());
	godot::_TagDB::register_global_type("JSONParseResult", JSONParseResult::___get_type_tag(), JSONParseResult::___get_base_type_tag());
	godot::_TagDB::register_global_type("IP_Unix", IP_Unix::___get_type_tag(), IP_Unix::___get_base_type_tag());
	godot::_TagDB::register_global_type("Geometry", Geometry::___get_type_tag(), Geometry::___get_base_type_tag());
	godot::_TagDB::register_global_type("ResourceLoader", ResourceLoader::___get_type_tag(), ResourceLoader::___get_base_type_tag());
	godot::_TagDB::register_global_type("ResourceSaver", ResourceSaver::___get_type_tag(), ResourceSaver::___get_base_type_tag());
	godot::_TagDB::register_global_type("OS", OS::___get_type_tag(), OS::___get_base_type_tag());
	godot::_TagDB::register_global_type("Engine", Engine::___get_type_tag(), Engine::___get_base_type_tag());
	godot::_TagDB::register_global_type("ClassDB", ClassDB::___get_type_tag(), ClassDB::___get_base_type_tag());
	godot::_TagDB::register_global_type("Marshalls", Marshalls::___get_type_tag(), Marshalls::___get_base_type_tag());
	godot::_TagDB::register_global_type("JSON", JSON::___get_type_tag(), JSON::___get_base_type_tag());
	godot::_TagDB::register_global_type("ProjectSettings", ProjectSettings::___get_type_tag(), ProjectSettings::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputMap", InputMap::___get_type_tag(), InputMap::___get_base_type_tag());
	godot::_TagDB::register_global_type("TranslationServer", TranslationServer::___get_type_tag(), TranslationServer::___get_base_type_tag());
	godot::_TagDB::register_global_type("Performance", Performance::___get_type_tag(), Performance::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualServer", VisualServer::___get_type_tag(), VisualServer::___get_base_type_tag());
	godot::_TagDB::register_global_type("InputDefault", InputDefault::___get_type_tag(), InputDefault::___get_base_type_tag());
	godot::_TagDB::register_global_type("Input", Input::___get_type_tag(), Input::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioServer", AudioServer::___get_type_tag(), AudioServer::___get_base_type_tag());
	godot::_TagDB::register_global_type("ARVRServer", ARVRServer::___get_type_tag(), ARVRServer::___get_base_type_tag());
	godot::_TagDB::register_global_type("PhysicsServer", PhysicsServer::___get_type_tag(), PhysicsServer::___get_base_type_tag());
	godot::_TagDB::register_global_type("Physics2DServer", Physics2DServer::___get_type_tag(), Physics2DServer::___get_base_type_tag());
	godot::_TagDB::register_global_type("ARVRInterface", ARVRInterface::___get_type_tag(), ARVRInterface::___get_base_type_tag());
	godot::_TagDB::register_global_type("ARVRPositionalTracker", ARVRPositionalTracker::___get_type_tag(), ARVRPositionalTracker::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioStream", AudioStream::___get_type_tag(), AudioStream::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioStreamPlayback", AudioStreamPlayback::___get_type_tag(), AudioStreamPlayback::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioStreamRandomPitch", AudioStreamRandomPitch::___get_type_tag(), AudioStreamRandomPitch::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffect", AudioEffect::___get_type_tag(), AudioEffect::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectEQ", AudioEffectEQ::___get_type_tag(), AudioEffectEQ::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectFilter", AudioEffectFilter::___get_type_tag(), AudioEffectFilter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioBusLayout", AudioBusLayout::___get_type_tag(), AudioBusLayout::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectAmplify", AudioEffectAmplify::___get_type_tag(), AudioEffectAmplify::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectReverb", AudioEffectReverb::___get_type_tag(), AudioEffectReverb::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectLowPassFilter", AudioEffectLowPassFilter::___get_type_tag(), AudioEffectLowPassFilter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectHighPassFilter", AudioEffectHighPassFilter::___get_type_tag(), AudioEffectHighPassFilter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectBandPassFilter", AudioEffectBandPassFilter::___get_type_tag(), AudioEffectBandPassFilter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectNotchFilter", AudioEffectNotchFilter::___get_type_tag(), AudioEffectNotchFilter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectBandLimitFilter", AudioEffectBandLimitFilter::___get_type_tag(), AudioEffectBandLimitFilter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectLowShelfFilter", AudioEffectLowShelfFilter::___get_type_tag(), AudioEffectLowShelfFilter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectHighShelfFilter", AudioEffectHighShelfFilter::___get_type_tag(), AudioEffectHighShelfFilter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectEQ6", AudioEffectEQ6::___get_type_tag(), AudioEffectEQ6::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectEQ10", AudioEffectEQ10::___get_type_tag(), AudioEffectEQ10::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectEQ21", AudioEffectEQ21::___get_type_tag(), AudioEffectEQ21::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectDistortion", AudioEffectDistortion::___get_type_tag(), AudioEffectDistortion::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectStereoEnhance", AudioEffectStereoEnhance::___get_type_tag(), AudioEffectStereoEnhance::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectPanner", AudioEffectPanner::___get_type_tag(), AudioEffectPanner::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectChorus", AudioEffectChorus::___get_type_tag(), AudioEffectChorus::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectDelay", AudioEffectDelay::___get_type_tag(), AudioEffectDelay::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectCompressor", AudioEffectCompressor::___get_type_tag(), AudioEffectCompressor::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectLimiter", AudioEffectLimiter::___get_type_tag(), AudioEffectLimiter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectPitchShift", AudioEffectPitchShift::___get_type_tag(), AudioEffectPitchShift::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioEffectPhaser", AudioEffectPhaser::___get_type_tag(), AudioEffectPhaser::___get_base_type_tag());
	godot::_TagDB::register_global_type("Physics2DDirectBodyState", Physics2DDirectBodyState::___get_type_tag(), Physics2DDirectBodyState::___get_base_type_tag());
	godot::_TagDB::register_global_type("Physics2DDirectSpaceState", Physics2DDirectSpaceState::___get_type_tag(), Physics2DDirectSpaceState::___get_base_type_tag());
	godot::_TagDB::register_global_type("Physics2DShapeQueryResult", Physics2DShapeQueryResult::___get_type_tag(), Physics2DShapeQueryResult::___get_base_type_tag());
	godot::_TagDB::register_global_type("Physics2DTestMotionResult", Physics2DTestMotionResult::___get_type_tag(), Physics2DTestMotionResult::___get_base_type_tag());
	godot::_TagDB::register_global_type("Physics2DShapeQueryParameters", Physics2DShapeQueryParameters::___get_type_tag(), Physics2DShapeQueryParameters::___get_base_type_tag());
	godot::_TagDB::register_global_type("PhysicsShapeQueryParameters", PhysicsShapeQueryParameters::___get_type_tag(), PhysicsShapeQueryParameters::___get_base_type_tag());
	godot::_TagDB::register_global_type("PhysicsDirectBodyState", PhysicsDirectBodyState::___get_type_tag(), PhysicsDirectBodyState::___get_base_type_tag());
	godot::_TagDB::register_global_type("PhysicsDirectSpaceState", PhysicsDirectSpaceState::___get_type_tag(), PhysicsDirectSpaceState::___get_base_type_tag());
	godot::_TagDB::register_global_type("PhysicsShapeQueryResult", PhysicsShapeQueryResult::___get_type_tag(), PhysicsShapeQueryResult::___get_base_type_tag());
	godot::_TagDB::register_global_type("CanvasModulate", CanvasModulate::___get_type_tag(), CanvasModulate::___get_base_type_tag());
	godot::_TagDB::register_global_type("ResourcePreloader", ResourcePreloader::___get_type_tag(), ResourcePreloader::___get_base_type_tag());
	godot::_TagDB::register_global_type("ButtonGroup", ButtonGroup::___get_type_tag(), ButtonGroup::___get_base_type_tag());
	godot::_TagDB::register_global_type("Control", Control::___get_type_tag(), Control::___get_base_type_tag());
	godot::_TagDB::register_global_type("InstancePlaceholder", InstancePlaceholder::___get_type_tag(), InstancePlaceholder::___get_base_type_tag());
	godot::_TagDB::register_global_type("Viewport", Viewport::___get_type_tag(), Viewport::___get_base_type_tag());
	godot::_TagDB::register_global_type("Node", Node::___get_type_tag(), Node::___get_base_type_tag());
	godot::_TagDB::register_global_type("ColorRect", ColorRect::___get_type_tag(), ColorRect::___get_base_type_tag());
	godot::_TagDB::register_global_type("NinePatchRect", NinePatchRect::___get_type_tag(), NinePatchRect::___get_base_type_tag());
	godot::_TagDB::register_global_type("TabContainer", TabContainer::___get_type_tag(), TabContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("Tabs", Tabs::___get_type_tag(), Tabs::___get_base_type_tag());
	godot::_TagDB::register_global_type("CanvasLayer", CanvasLayer::___get_type_tag(), CanvasLayer::___get_base_type_tag());
	godot::_TagDB::register_global_type("Texture", Texture::___get_type_tag(), Texture::___get_base_type_tag());
	godot::_TagDB::register_global_type("World", World::___get_type_tag(), World::___get_base_type_tag());
	godot::_TagDB::register_global_type("World2D", World2D::___get_type_tag(), World2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("BaseButton", BaseButton::___get_type_tag(), BaseButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("Label", Label::___get_type_tag(), Label::___get_base_type_tag());
	godot::_TagDB::register_global_type("Range", Range::___get_type_tag(), Range::___get_base_type_tag());
	godot::_TagDB::register_global_type("CanvasItem", CanvasItem::___get_type_tag(), CanvasItem::___get_base_type_tag());
	godot::_TagDB::register_global_type("ShortCut", ShortCut::___get_type_tag(), ShortCut::___get_base_type_tag());
	godot::_TagDB::register_global_type("Button", Button::___get_type_tag(), Button::___get_base_type_tag());
	godot::_TagDB::register_global_type("ViewportTexture", ViewportTexture::___get_type_tag(), ViewportTexture::___get_base_type_tag());
	godot::_TagDB::register_global_type("HTTPRequest", HTTPRequest::___get_type_tag(), HTTPRequest::___get_base_type_tag());
	godot::_TagDB::register_global_type("VBoxContainer", VBoxContainer::___get_type_tag(), VBoxContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("GridContainer", GridContainer::___get_type_tag(), GridContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("CenterContainer", CenterContainer::___get_type_tag(), CenterContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("ScrollContainer", ScrollContainer::___get_type_tag(), ScrollContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("PanelContainer", PanelContainer::___get_type_tag(), PanelContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("SplitContainer", SplitContainer::___get_type_tag(), SplitContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("VSplitContainer", VSplitContainer::___get_type_tag(), VSplitContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("GraphNode", GraphNode::___get_type_tag(), GraphNode::___get_base_type_tag());
	godot::_TagDB::register_global_type("GraphEdit", GraphEdit::___get_type_tag(), GraphEdit::___get_base_type_tag());
	godot::_TagDB::register_global_type("Node2D", Node2D::___get_type_tag(), Node2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("ScrollBar", ScrollBar::___get_type_tag(), ScrollBar::___get_base_type_tag());
	godot::_TagDB::register_global_type("HScrollBar", HScrollBar::___get_type_tag(), HScrollBar::___get_base_type_tag());
	godot::_TagDB::register_global_type("VScrollBar", VScrollBar::___get_type_tag(), VScrollBar::___get_base_type_tag());
	godot::_TagDB::register_global_type("ProgressBar", ProgressBar::___get_type_tag(), ProgressBar::___get_base_type_tag());
	godot::_TagDB::register_global_type("Slider", Slider::___get_type_tag(), Slider::___get_base_type_tag());
	godot::_TagDB::register_global_type("HSlider", HSlider::___get_type_tag(), HSlider::___get_base_type_tag());
	godot::_TagDB::register_global_type("VSlider", VSlider::___get_type_tag(), VSlider::___get_base_type_tag());
	godot::_TagDB::register_global_type("Popup", Popup::___get_type_tag(), Popup::___get_base_type_tag());
	godot::_TagDB::register_global_type("PopupPanel", PopupPanel::___get_type_tag(), PopupPanel::___get_base_type_tag());
	godot::_TagDB::register_global_type("MenuButton", MenuButton::___get_type_tag(), MenuButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("CheckBox", CheckBox::___get_type_tag(), CheckBox::___get_base_type_tag());
	godot::_TagDB::register_global_type("CheckButton", CheckButton::___get_type_tag(), CheckButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("ToolButton", ToolButton::___get_type_tag(), ToolButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("LinkButton", LinkButton::___get_type_tag(), LinkButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("Panel", Panel::___get_type_tag(), Panel::___get_base_type_tag());
	godot::_TagDB::register_global_type("TextureRect", TextureRect::___get_type_tag(), TextureRect::___get_base_type_tag());
	godot::_TagDB::register_global_type("TextureProgress", TextureProgress::___get_type_tag(), TextureProgress::___get_base_type_tag());
	godot::_TagDB::register_global_type("ItemList", ItemList::___get_type_tag(), ItemList::___get_base_type_tag());
	godot::_TagDB::register_global_type("WindowDialog", WindowDialog::___get_type_tag(), WindowDialog::___get_base_type_tag());
	godot::_TagDB::register_global_type("AcceptDialog", AcceptDialog::___get_type_tag(), AcceptDialog::___get_base_type_tag());
	godot::_TagDB::register_global_type("Separator", Separator::___get_type_tag(), Separator::___get_base_type_tag());
	godot::_TagDB::register_global_type("HSeparator", HSeparator::___get_type_tag(), HSeparator::___get_base_type_tag());
	godot::_TagDB::register_global_type("VSeparator", VSeparator::___get_type_tag(), VSeparator::___get_base_type_tag());
	godot::_TagDB::register_global_type("TextureButton", TextureButton::___get_type_tag(), TextureButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("BitMap", BitMap::___get_type_tag(), BitMap::___get_base_type_tag());
	godot::_TagDB::register_global_type("Container", Container::___get_type_tag(), Container::___get_base_type_tag());
	godot::_TagDB::register_global_type("BoxContainer", BoxContainer::___get_type_tag(), BoxContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("HBoxContainer", HBoxContainer::___get_type_tag(), HBoxContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("HSplitContainer", HSplitContainer::___get_type_tag(), HSplitContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("Theme", Theme::___get_type_tag(), Theme::___get_base_type_tag());
	godot::_TagDB::register_global_type("Timer", Timer::___get_type_tag(), Timer::___get_base_type_tag());
	godot::_TagDB::register_global_type("ConfirmationDialog", ConfirmationDialog::___get_type_tag(), ConfirmationDialog::___get_base_type_tag());
	godot::_TagDB::register_global_type("FileDialog", FileDialog::___get_type_tag(), FileDialog::___get_base_type_tag());
	godot::_TagDB::register_global_type("LineEdit", LineEdit::___get_type_tag(), LineEdit::___get_base_type_tag());
	godot::_TagDB::register_global_type("PopupMenu", PopupMenu::___get_type_tag(), PopupMenu::___get_base_type_tag());
	godot::_TagDB::register_global_type("Tree", Tree::___get_type_tag(), Tree::___get_base_type_tag());
	godot::_TagDB::register_global_type("TextEdit", TextEdit::___get_type_tag(), TextEdit::___get_base_type_tag());
	godot::_TagDB::register_global_type("TreeItem", TreeItem::___get_type_tag(), TreeItem::___get_base_type_tag());
	godot::_TagDB::register_global_type("OptionButton", OptionButton::___get_type_tag(), OptionButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("SpinBox", SpinBox::___get_type_tag(), SpinBox::___get_base_type_tag());
	godot::_TagDB::register_global_type("ReferenceRect", ReferenceRect::___get_type_tag(), ReferenceRect::___get_base_type_tag());
	godot::_TagDB::register_global_type("ColorPicker", ColorPicker::___get_type_tag(), ColorPicker::___get_base_type_tag());
	godot::_TagDB::register_global_type("ColorPickerButton", ColorPickerButton::___get_type_tag(), ColorPickerButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("RichTextLabel", RichTextLabel::___get_type_tag(), RichTextLabel::___get_base_type_tag());
	godot::_TagDB::register_global_type("PopupDialog", PopupDialog::___get_type_tag(), PopupDialog::___get_base_type_tag());
	godot::_TagDB::register_global_type("VideoPlayer", VideoPlayer::___get_type_tag(), VideoPlayer::___get_base_type_tag());
	godot::_TagDB::register_global_type("VideoStream", VideoStream::___get_type_tag(), VideoStream::___get_base_type_tag());
	godot::_TagDB::register_global_type("MarginContainer", MarginContainer::___get_type_tag(), MarginContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("ViewportContainer", ViewportContainer::___get_type_tag(), ViewportContainer::___get_base_type_tag());
	godot::_TagDB::register_global_type("Spatial", Spatial::___get_type_tag(), Spatial::___get_base_type_tag());
	godot::_TagDB::register_global_type("SpatialGizmo", SpatialGizmo::___get_type_tag(), SpatialGizmo::___get_base_type_tag());
	godot::_TagDB::register_global_type("Skeleton", Skeleton::___get_type_tag(), Skeleton::___get_base_type_tag());
	godot::_TagDB::register_global_type("AnimationPlayer", AnimationPlayer::___get_type_tag(), AnimationPlayer::___get_base_type_tag());
	godot::_TagDB::register_global_type("Tween", Tween::___get_type_tag(), Tween::___get_base_type_tag());
	godot::_TagDB::register_global_type("BoneAttachment", BoneAttachment::___get_type_tag(), BoneAttachment::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualInstance", VisualInstance::___get_type_tag(), VisualInstance::___get_base_type_tag());
	godot::_TagDB::register_global_type("GeometryInstance", GeometryInstance::___get_type_tag(), GeometryInstance::___get_base_type_tag());
	godot::_TagDB::register_global_type("Camera", Camera::___get_type_tag(), Camera::___get_base_type_tag());
	godot::_TagDB::register_global_type("Environment", Environment::___get_type_tag(), Environment::___get_base_type_tag());
	godot::_TagDB::register_global_type("Listener", Listener::___get_type_tag(), Listener::___get_base_type_tag());
	godot::_TagDB::register_global_type("ARVRCamera", ARVRCamera::___get_type_tag(), ARVRCamera::___get_base_type_tag());
	godot::_TagDB::register_global_type("ARVRController", ARVRController::___get_type_tag(), ARVRController::___get_base_type_tag());
	godot::_TagDB::register_global_type("ARVRAnchor", ARVRAnchor::___get_type_tag(), ARVRAnchor::___get_base_type_tag());
	godot::_TagDB::register_global_type("ARVROrigin", ARVROrigin::___get_type_tag(), ARVROrigin::___get_base_type_tag());
	godot::_TagDB::register_global_type("InterpolatedCamera", InterpolatedCamera::___get_type_tag(), InterpolatedCamera::___get_base_type_tag());
	godot::_TagDB::register_global_type("MeshInstance", MeshInstance::___get_type_tag(), MeshInstance::___get_base_type_tag());
	godot::_TagDB::register_global_type("Mesh", Mesh::___get_type_tag(), Mesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("ImmediateGeometry", ImmediateGeometry::___get_type_tag(), ImmediateGeometry::___get_base_type_tag());
	godot::_TagDB::register_global_type("SpriteBase3D", SpriteBase3D::___get_type_tag(), SpriteBase3D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Sprite3D", Sprite3D::___get_type_tag(), Sprite3D::___get_base_type_tag());
	godot::_TagDB::register_global_type("AnimatedSprite3D", AnimatedSprite3D::___get_type_tag(), AnimatedSprite3D::___get_base_type_tag());
	godot::_TagDB::register_global_type("SpriteFrames", SpriteFrames::___get_type_tag(), SpriteFrames::___get_base_type_tag());
	godot::_TagDB::register_global_type("Light", Light::___get_type_tag(), Light::___get_base_type_tag());
	godot::_TagDB::register_global_type("DirectionalLight", DirectionalLight::___get_type_tag(), DirectionalLight::___get_base_type_tag());
	godot::_TagDB::register_global_type("OmniLight", OmniLight::___get_type_tag(), OmniLight::___get_base_type_tag());
	godot::_TagDB::register_global_type("SpotLight", SpotLight::___get_type_tag(), SpotLight::___get_base_type_tag());
	godot::_TagDB::register_global_type("ReflectionProbe", ReflectionProbe::___get_type_tag(), ReflectionProbe::___get_base_type_tag());
	godot::_TagDB::register_global_type("GIProbe", GIProbe::___get_type_tag(), GIProbe::___get_base_type_tag());
	godot::_TagDB::register_global_type("GIProbeData", GIProbeData::___get_type_tag(), GIProbeData::___get_base_type_tag());
	godot::_TagDB::register_global_type("BakedLightmap", BakedLightmap::___get_type_tag(), BakedLightmap::___get_base_type_tag());
	godot::_TagDB::register_global_type("BakedLightmapData", BakedLightmapData::___get_type_tag(), BakedLightmapData::___get_base_type_tag());
	godot::_TagDB::register_global_type("AnimationTreePlayer", AnimationTreePlayer::___get_type_tag(), AnimationTreePlayer::___get_base_type_tag());
	godot::_TagDB::register_global_type("Particles", Particles::___get_type_tag(), Particles::___get_base_type_tag());
	godot::_TagDB::register_global_type("Position3D", Position3D::___get_type_tag(), Position3D::___get_base_type_tag());
	godot::_TagDB::register_global_type("NavigationMeshInstance", NavigationMeshInstance::___get_type_tag(), NavigationMeshInstance::___get_base_type_tag());
	godot::_TagDB::register_global_type("NavigationMesh", NavigationMesh::___get_type_tag(), NavigationMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("Navigation", Navigation::___get_type_tag(), Navigation::___get_base_type_tag());
	godot::_TagDB::register_global_type("CollisionObject", CollisionObject::___get_type_tag(), CollisionObject::___get_base_type_tag());
	godot::_TagDB::register_global_type("PhysicsBody", PhysicsBody::___get_type_tag(), PhysicsBody::___get_base_type_tag());
	godot::_TagDB::register_global_type("StaticBody", StaticBody::___get_type_tag(), StaticBody::___get_base_type_tag());
	godot::_TagDB::register_global_type("RigidBody", RigidBody::___get_type_tag(), RigidBody::___get_base_type_tag());
	godot::_TagDB::register_global_type("KinematicCollision", KinematicCollision::___get_type_tag(), KinematicCollision::___get_base_type_tag());
	godot::_TagDB::register_global_type("KinematicBody", KinematicBody::___get_type_tag(), KinematicBody::___get_base_type_tag());
	godot::_TagDB::register_global_type("VehicleBody", VehicleBody::___get_type_tag(), VehicleBody::___get_base_type_tag());
	godot::_TagDB::register_global_type("VehicleWheel", VehicleWheel::___get_type_tag(), VehicleWheel::___get_base_type_tag());
	godot::_TagDB::register_global_type("Area", Area::___get_type_tag(), Area::___get_base_type_tag());
	godot::_TagDB::register_global_type("ProximityGroup", ProximityGroup::___get_type_tag(), ProximityGroup::___get_base_type_tag());
	godot::_TagDB::register_global_type("CollisionShape", CollisionShape::___get_type_tag(), CollisionShape::___get_base_type_tag());
	godot::_TagDB::register_global_type("Shape", Shape::___get_type_tag(), Shape::___get_base_type_tag());
	godot::_TagDB::register_global_type("CollisionPolygon", CollisionPolygon::___get_type_tag(), CollisionPolygon::___get_base_type_tag());
	godot::_TagDB::register_global_type("RayCast", RayCast::___get_type_tag(), RayCast::___get_base_type_tag());
	godot::_TagDB::register_global_type("MultiMeshInstance", MultiMeshInstance::___get_type_tag(), MultiMeshInstance::___get_base_type_tag());
	godot::_TagDB::register_global_type("MultiMesh", MultiMesh::___get_type_tag(), MultiMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("Curve3D", Curve3D::___get_type_tag(), Curve3D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Path", Path::___get_type_tag(), Path::___get_base_type_tag());
	godot::_TagDB::register_global_type("PathFollow", PathFollow::___get_type_tag(), PathFollow::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisibilityNotifier", VisibilityNotifier::___get_type_tag(), VisibilityNotifier::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisibilityEnabler", VisibilityEnabler::___get_type_tag(), VisibilityEnabler::___get_base_type_tag());
	godot::_TagDB::register_global_type("WorldEnvironment", WorldEnvironment::___get_type_tag(), WorldEnvironment::___get_base_type_tag());
	godot::_TagDB::register_global_type("RemoteTransform", RemoteTransform::___get_type_tag(), RemoteTransform::___get_base_type_tag());
	godot::_TagDB::register_global_type("Joint", Joint::___get_type_tag(), Joint::___get_base_type_tag());
	godot::_TagDB::register_global_type("PinJoint", PinJoint::___get_type_tag(), PinJoint::___get_base_type_tag());
	godot::_TagDB::register_global_type("HingeJoint", HingeJoint::___get_type_tag(), HingeJoint::___get_base_type_tag());
	godot::_TagDB::register_global_type("SliderJoint", SliderJoint::___get_type_tag(), SliderJoint::___get_base_type_tag());
	godot::_TagDB::register_global_type("ConeTwistJoint", ConeTwistJoint::___get_type_tag(), ConeTwistJoint::___get_base_type_tag());
	godot::_TagDB::register_global_type("Generic6DOFJoint", Generic6DOFJoint::___get_type_tag(), Generic6DOFJoint::___get_base_type_tag());
	godot::_TagDB::register_global_type("MeshLibrary", MeshLibrary::___get_type_tag(), MeshLibrary::___get_base_type_tag());
	godot::_TagDB::register_global_type("Shader", Shader::___get_type_tag(), Shader::___get_base_type_tag());
	godot::_TagDB::register_global_type("Material", Material::___get_type_tag(), Material::___get_base_type_tag());
	godot::_TagDB::register_global_type("ShaderMaterial", ShaderMaterial::___get_type_tag(), ShaderMaterial::___get_base_type_tag());
	godot::_TagDB::register_global_type("CanvasItemMaterial", CanvasItemMaterial::___get_type_tag(), CanvasItemMaterial::___get_base_type_tag());
	godot::_TagDB::register_global_type("Particles2D", Particles2D::___get_type_tag(), Particles2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Sprite", Sprite::___get_type_tag(), Sprite::___get_base_type_tag());
	godot::_TagDB::register_global_type("AnimatedSprite", AnimatedSprite::___get_type_tag(), AnimatedSprite::___get_base_type_tag());
	godot::_TagDB::register_global_type("Position2D", Position2D::___get_type_tag(), Position2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Line2D", Line2D::___get_type_tag(), Line2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Gradient", Gradient::___get_type_tag(), Gradient::___get_base_type_tag());
	godot::_TagDB::register_global_type("MeshInstance2D", MeshInstance2D::___get_type_tag(), MeshInstance2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("CollisionObject2D", CollisionObject2D::___get_type_tag(), CollisionObject2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("PhysicsBody2D", PhysicsBody2D::___get_type_tag(), PhysicsBody2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("StaticBody2D", StaticBody2D::___get_type_tag(), StaticBody2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("RigidBody2D", RigidBody2D::___get_type_tag(), RigidBody2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("KinematicBody2D", KinematicBody2D::___get_type_tag(), KinematicBody2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("KinematicCollision2D", KinematicCollision2D::___get_type_tag(), KinematicCollision2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Area2D", Area2D::___get_type_tag(), Area2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("CollisionShape2D", CollisionShape2D::___get_type_tag(), CollisionShape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Shape2D", Shape2D::___get_type_tag(), Shape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("CollisionPolygon2D", CollisionPolygon2D::___get_type_tag(), CollisionPolygon2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("RayCast2D", RayCast2D::___get_type_tag(), RayCast2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisibilityNotifier2D", VisibilityNotifier2D::___get_type_tag(), VisibilityNotifier2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisibilityEnabler2D", VisibilityEnabler2D::___get_type_tag(), VisibilityEnabler2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Polygon2D", Polygon2D::___get_type_tag(), Polygon2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Light2D", Light2D::___get_type_tag(), Light2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("LightOccluder2D", LightOccluder2D::___get_type_tag(), LightOccluder2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("OccluderPolygon2D", OccluderPolygon2D::___get_type_tag(), OccluderPolygon2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("YSort", YSort::___get_type_tag(), YSort::___get_base_type_tag());
	godot::_TagDB::register_global_type("BackBufferCopy", BackBufferCopy::___get_type_tag(), BackBufferCopy::___get_base_type_tag());
	godot::_TagDB::register_global_type("Camera2D", Camera2D::___get_type_tag(), Camera2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Joint2D", Joint2D::___get_type_tag(), Joint2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("PinJoint2D", PinJoint2D::___get_type_tag(), PinJoint2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("GrooveJoint2D", GrooveJoint2D::___get_type_tag(), GrooveJoint2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("DampedSpringJoint2D", DampedSpringJoint2D::___get_type_tag(), DampedSpringJoint2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("TileSet", TileSet::___get_type_tag(), TileSet::___get_base_type_tag());
	godot::_TagDB::register_global_type("TileMap", TileMap::___get_type_tag(), TileMap::___get_base_type_tag());
	godot::_TagDB::register_global_type("ParallaxBackground", ParallaxBackground::___get_type_tag(), ParallaxBackground::___get_base_type_tag());
	godot::_TagDB::register_global_type("ParallaxLayer", ParallaxLayer::___get_type_tag(), ParallaxLayer::___get_base_type_tag());
	godot::_TagDB::register_global_type("TouchScreenButton", TouchScreenButton::___get_type_tag(), TouchScreenButton::___get_base_type_tag());
	godot::_TagDB::register_global_type("RemoteTransform2D", RemoteTransform2D::___get_type_tag(), RemoteTransform2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("ArrayMesh", ArrayMesh::___get_type_tag(), ArrayMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("PrimitiveMesh", PrimitiveMesh::___get_type_tag(), PrimitiveMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("CapsuleMesh", CapsuleMesh::___get_type_tag(), CapsuleMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("CubeMesh", CubeMesh::___get_type_tag(), CubeMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("CylinderMesh", CylinderMesh::___get_type_tag(), CylinderMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("PlaneMesh", PlaneMesh::___get_type_tag(), PlaneMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("PrismMesh", PrismMesh::___get_type_tag(), PrismMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("QuadMesh", QuadMesh::___get_type_tag(), QuadMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("SphereMesh", SphereMesh::___get_type_tag(), SphereMesh::___get_base_type_tag());
	godot::_TagDB::register_global_type("SpatialMaterial", SpatialMaterial::___get_type_tag(), SpatialMaterial::___get_base_type_tag());
	godot::_TagDB::register_global_type("ParticlesMaterial", ParticlesMaterial::___get_type_tag(), ParticlesMaterial::___get_base_type_tag());
	godot::_TagDB::register_global_type("CurveTexture", CurveTexture::___get_type_tag(), CurveTexture::___get_base_type_tag());
	godot::_TagDB::register_global_type("GradientTexture", GradientTexture::___get_type_tag(), GradientTexture::___get_base_type_tag());
	godot::_TagDB::register_global_type("RayShape", RayShape::___get_type_tag(), RayShape::___get_base_type_tag());
	godot::_TagDB::register_global_type("SphereShape", SphereShape::___get_type_tag(), SphereShape::___get_base_type_tag());
	godot::_TagDB::register_global_type("BoxShape", BoxShape::___get_type_tag(), BoxShape::___get_base_type_tag());
	godot::_TagDB::register_global_type("CapsuleShape", CapsuleShape::___get_type_tag(), CapsuleShape::___get_base_type_tag());
	godot::_TagDB::register_global_type("PlaneShape", PlaneShape::___get_type_tag(), PlaneShape::___get_base_type_tag());
	godot::_TagDB::register_global_type("ConvexPolygonShape", ConvexPolygonShape::___get_type_tag(), ConvexPolygonShape::___get_base_type_tag());
	godot::_TagDB::register_global_type("ConcavePolygonShape", ConcavePolygonShape::___get_type_tag(), ConcavePolygonShape::___get_base_type_tag());
	godot::_TagDB::register_global_type("SurfaceTool", SurfaceTool::___get_type_tag(), SurfaceTool::___get_base_type_tag());
	godot::_TagDB::register_global_type("MeshDataTool", MeshDataTool::___get_type_tag(), MeshDataTool::___get_base_type_tag());
	godot::_TagDB::register_global_type("SpatialVelocityTracker", SpatialVelocityTracker::___get_type_tag(), SpatialVelocityTracker::___get_base_type_tag());
	godot::_TagDB::register_global_type("Sky", Sky::___get_type_tag(), Sky::___get_base_type_tag());
	godot::_TagDB::register_global_type("PanoramaSky", PanoramaSky::___get_type_tag(), PanoramaSky::___get_base_type_tag());
	godot::_TagDB::register_global_type("ProceduralSky", ProceduralSky::___get_type_tag(), ProceduralSky::___get_base_type_tag());
	godot::_TagDB::register_global_type("StreamTexture", StreamTexture::___get_type_tag(), StreamTexture::___get_base_type_tag());
	godot::_TagDB::register_global_type("ImageTexture", ImageTexture::___get_type_tag(), ImageTexture::___get_base_type_tag());
	godot::_TagDB::register_global_type("AtlasTexture", AtlasTexture::___get_type_tag(), AtlasTexture::___get_base_type_tag());
	godot::_TagDB::register_global_type("LargeTexture", LargeTexture::___get_type_tag(), LargeTexture::___get_base_type_tag());
	godot::_TagDB::register_global_type("Curve", Curve::___get_type_tag(), Curve::___get_base_type_tag());
	godot::_TagDB::register_global_type("ProxyTexture", ProxyTexture::___get_type_tag(), ProxyTexture::___get_base_type_tag());
	godot::_TagDB::register_global_type("CubeMap", CubeMap::___get_type_tag(), CubeMap::___get_base_type_tag());
	godot::_TagDB::register_global_type("Animation", Animation::___get_type_tag(), Animation::___get_base_type_tag());
	godot::_TagDB::register_global_type("Font", Font::___get_type_tag(), Font::___get_base_type_tag());
	godot::_TagDB::register_global_type("BitmapFont", BitmapFont::___get_type_tag(), BitmapFont::___get_base_type_tag());
	godot::_TagDB::register_global_type("DynamicFontData", DynamicFontData::___get_type_tag(), DynamicFontData::___get_base_type_tag());
	godot::_TagDB::register_global_type("DynamicFont", DynamicFont::___get_type_tag(), DynamicFont::___get_base_type_tag());
	godot::_TagDB::register_global_type("StyleBox", StyleBox::___get_type_tag(), StyleBox::___get_base_type_tag());
	godot::_TagDB::register_global_type("StyleBoxEmpty", StyleBoxEmpty::___get_type_tag(), StyleBoxEmpty::___get_base_type_tag());
	godot::_TagDB::register_global_type("StyleBoxTexture", StyleBoxTexture::___get_type_tag(), StyleBoxTexture::___get_base_type_tag());
	godot::_TagDB::register_global_type("StyleBoxFlat", StyleBoxFlat::___get_type_tag(), StyleBoxFlat::___get_base_type_tag());
	godot::_TagDB::register_global_type("StyleBoxLine", StyleBoxLine::___get_type_tag(), StyleBoxLine::___get_base_type_tag());
	godot::_TagDB::register_global_type("PolygonPathFinder", PolygonPathFinder::___get_type_tag(), PolygonPathFinder::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioStreamPlayer", AudioStreamPlayer::___get_type_tag(), AudioStreamPlayer::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioStreamPlayer2D", AudioStreamPlayer2D::___get_type_tag(), AudioStreamPlayer2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioStreamPlayer3D", AudioStreamPlayer3D::___get_type_tag(), AudioStreamPlayer3D::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioStreamSample", AudioStreamSample::___get_type_tag(), AudioStreamSample::___get_base_type_tag());
	godot::_TagDB::register_global_type("LineShape2D", LineShape2D::___get_type_tag(), LineShape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("SegmentShape2D", SegmentShape2D::___get_type_tag(), SegmentShape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("RayShape2D", RayShape2D::___get_type_tag(), RayShape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("CircleShape2D", CircleShape2D::___get_type_tag(), CircleShape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("RectangleShape2D", RectangleShape2D::___get_type_tag(), RectangleShape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("CapsuleShape2D", CapsuleShape2D::___get_type_tag(), CapsuleShape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("ConvexPolygonShape2D", ConvexPolygonShape2D::___get_type_tag(), ConvexPolygonShape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("ConcavePolygonShape2D", ConcavePolygonShape2D::___get_type_tag(), ConcavePolygonShape2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Curve2D", Curve2D::___get_type_tag(), Curve2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Path2D", Path2D::___get_type_tag(), Path2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("PathFollow2D", PathFollow2D::___get_type_tag(), PathFollow2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("Navigation2D", Navigation2D::___get_type_tag(), Navigation2D::___get_base_type_tag());
	godot::_TagDB::register_global_type("NavigationPolygon", NavigationPolygon::___get_type_tag(), NavigationPolygon::___get_base_type_tag());
	godot::_TagDB::register_global_type("NavigationPolygonInstance", NavigationPolygonInstance::___get_type_tag(), NavigationPolygonInstance::___get_base_type_tag());
	godot::_TagDB::register_global_type("SceneState", SceneState::___get_type_tag(), SceneState::___get_base_type_tag());
	godot::_TagDB::register_global_type("PackedScene", PackedScene::___get_type_tag(), PackedScene::___get_base_type_tag());
	godot::_TagDB::register_global_type("SceneTree", SceneTree::___get_type_tag(), SceneTree::___get_base_type_tag());
	godot::_TagDB::register_global_type("SceneTreeTimer", SceneTreeTimer::___get_type_tag(), SceneTreeTimer::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorPlugin", EditorPlugin::___get_type_tag(), EditorPlugin::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorImportPlugin", EditorImportPlugin::___get_type_tag(), EditorImportPlugin::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorScript", EditorScript::___get_type_tag(), EditorScript::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorSelection", EditorSelection::___get_type_tag(), EditorSelection::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorFileDialog", EditorFileDialog::___get_type_tag(), EditorFileDialog::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorSettings", EditorSettings::___get_type_tag(), EditorSettings::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorSpatialGizmo", EditorSpatialGizmo::___get_type_tag(), EditorSpatialGizmo::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorResourcePreview", EditorResourcePreview::___get_type_tag(), EditorResourcePreview::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorResourcePreviewGenerator", EditorResourcePreviewGenerator::___get_type_tag(), EditorResourcePreviewGenerator::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorFileSystem", EditorFileSystem::___get_type_tag(), EditorFileSystem::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorFileSystemDirectory", EditorFileSystemDirectory::___get_type_tag(), EditorFileSystemDirectory::___get_base_type_tag());
	godot::_TagDB::register_global_type("ScriptEditor", ScriptEditor::___get_type_tag(), ScriptEditor::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorInterface", EditorInterface::___get_type_tag(), EditorInterface::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorExportPlugin", EditorExportPlugin::___get_type_tag(), EditorExportPlugin::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorResourceConversionPlugin", EditorResourceConversionPlugin::___get_type_tag(), EditorResourceConversionPlugin::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorSceneImporter", EditorSceneImporter::___get_type_tag(), EditorSceneImporter::___get_base_type_tag());
	godot::_TagDB::register_global_type("EditorScenePostImport", EditorScenePostImport::___get_type_tag(), EditorScenePostImport::___get_base_type_tag());
	godot::_TagDB::register_global_type("JavaScript", JavaScript::___get_type_tag(), JavaScript::___get_base_type_tag());
	godot::_TagDB::register_global_type("NetworkedMultiplayerENet", NetworkedMultiplayerENet::___get_type_tag(), NetworkedMultiplayerENet::___get_base_type_tag());
	godot::_TagDB::register_global_type("GDNativeLibrary", GDNativeLibrary::___get_type_tag(), GDNativeLibrary::___get_base_type_tag());
	godot::_TagDB::register_global_type("GDNative", GDNative::___get_type_tag(), GDNative::___get_base_type_tag());
	godot::_TagDB::register_global_type("ARVRInterfaceGDNative", ARVRInterfaceGDNative::___get_type_tag(), ARVRInterfaceGDNative::___get_base_type_tag());
	godot::_TagDB::register_global_type("NativeScript", NativeScript::___get_type_tag(), NativeScript::___get_base_type_tag());
	godot::_TagDB::register_global_type("PluginScript", PluginScript::___get_type_tag(), PluginScript::___get_base_type_tag());
	godot::_TagDB::register_global_type("GDScript", GDScript::___get_type_tag(), GDScript::___get_base_type_tag());
	godot::_TagDB::register_global_type("GDScriptFunctionState", GDScriptFunctionState::___get_type_tag(), GDScriptFunctionState::___get_base_type_tag());
	godot::_TagDB::register_global_type("GridMap", GridMap::___get_type_tag(), GridMap::___get_base_type_tag());
	godot::_TagDB::register_global_type("RegExMatch", RegExMatch::___get_type_tag(), RegExMatch::___get_base_type_tag());
	godot::_TagDB::register_global_type("RegEx", RegEx::___get_type_tag(), RegEx::___get_base_type_tag());
	godot::_TagDB::register_global_type("ResourceImporterOGGVorbis", ResourceImporterOGGVorbis::___get_type_tag(), ResourceImporterOGGVorbis::___get_base_type_tag());
	godot::_TagDB::register_global_type("ResourceImporter", ResourceImporter::___get_type_tag(), ResourceImporter::___get_base_type_tag());
	godot::_TagDB::register_global_type("AudioStreamOGGVorbis", AudioStreamOGGVorbis::___get_type_tag(), AudioStreamOGGVorbis::___get_base_type_tag());
	godot::_TagDB::register_global_type("ResourceImporterTheora", ResourceImporterTheora::___get_type_tag(), ResourceImporterTheora::___get_base_type_tag());
	godot::_TagDB::register_global_type("VideoStreamTheora", VideoStreamTheora::___get_type_tag(), VideoStreamTheora::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScript", VisualScript::___get_type_tag(), VisualScript::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptNode", VisualScriptNode::___get_type_tag(), VisualScriptNode::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptFunctionState", VisualScriptFunctionState::___get_type_tag(), VisualScriptFunctionState::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptFunction", VisualScriptFunction::___get_type_tag(), VisualScriptFunction::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptOperator", VisualScriptOperator::___get_type_tag(), VisualScriptOperator::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptVariableSet", VisualScriptVariableSet::___get_type_tag(), VisualScriptVariableSet::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptVariableGet", VisualScriptVariableGet::___get_type_tag(), VisualScriptVariableGet::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptConstant", VisualScriptConstant::___get_type_tag(), VisualScriptConstant::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptIndexGet", VisualScriptIndexGet::___get_type_tag(), VisualScriptIndexGet::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptIndexSet", VisualScriptIndexSet::___get_type_tag(), VisualScriptIndexSet::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptGlobalConstant", VisualScriptGlobalConstant::___get_type_tag(), VisualScriptGlobalConstant::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptClassConstant", VisualScriptClassConstant::___get_type_tag(), VisualScriptClassConstant::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptMathConstant", VisualScriptMathConstant::___get_type_tag(), VisualScriptMathConstant::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptBasicTypeConstant", VisualScriptBasicTypeConstant::___get_type_tag(), VisualScriptBasicTypeConstant::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptEngineSingleton", VisualScriptEngineSingleton::___get_type_tag(), VisualScriptEngineSingleton::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptSceneNode", VisualScriptSceneNode::___get_type_tag(), VisualScriptSceneNode::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptSceneTree", VisualScriptSceneTree::___get_type_tag(), VisualScriptSceneTree::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptResourcePath", VisualScriptResourcePath::___get_type_tag(), VisualScriptResourcePath::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptSelf", VisualScriptSelf::___get_type_tag(), VisualScriptSelf::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptCustomNode", VisualScriptCustomNode::___get_type_tag(), VisualScriptCustomNode::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptSubCall", VisualScriptSubCall::___get_type_tag(), VisualScriptSubCall::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptComment", VisualScriptComment::___get_type_tag(), VisualScriptComment::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptConstructor", VisualScriptConstructor::___get_type_tag(), VisualScriptConstructor::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptLocalVar", VisualScriptLocalVar::___get_type_tag(), VisualScriptLocalVar::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptLocalVarSet", VisualScriptLocalVarSet::___get_type_tag(), VisualScriptLocalVarSet::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptInputAction", VisualScriptInputAction::___get_type_tag(), VisualScriptInputAction::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptDeconstruct", VisualScriptDeconstruct::___get_type_tag(), VisualScriptDeconstruct::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptPreload", VisualScriptPreload::___get_type_tag(), VisualScriptPreload::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptTypeCast", VisualScriptTypeCast::___get_type_tag(), VisualScriptTypeCast::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptFunctionCall", VisualScriptFunctionCall::___get_type_tag(), VisualScriptFunctionCall::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptPropertySet", VisualScriptPropertySet::___get_type_tag(), VisualScriptPropertySet::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptPropertyGet", VisualScriptPropertyGet::___get_type_tag(), VisualScriptPropertyGet::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptEmitSignal", VisualScriptEmitSignal::___get_type_tag(), VisualScriptEmitSignal::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptReturn", VisualScriptReturn::___get_type_tag(), VisualScriptReturn::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptCondition", VisualScriptCondition::___get_type_tag(), VisualScriptCondition::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptWhile", VisualScriptWhile::___get_type_tag(), VisualScriptWhile::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptIterator", VisualScriptIterator::___get_type_tag(), VisualScriptIterator::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptSequence", VisualScriptSequence::___get_type_tag(), VisualScriptSequence::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptSwitch", VisualScriptSwitch::___get_type_tag(), VisualScriptSwitch::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptSelect", VisualScriptSelect::___get_type_tag(), VisualScriptSelect::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptYield", VisualScriptYield::___get_type_tag(), VisualScriptYield::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptYieldSignal", VisualScriptYieldSignal::___get_type_tag(), VisualScriptYieldSignal::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptBuiltinFunc", VisualScriptBuiltinFunc::___get_type_tag(), VisualScriptBuiltinFunc::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptExpression", VisualScriptExpression::___get_type_tag(), VisualScriptExpression::___get_base_type_tag());
	godot::_TagDB::register_global_type("WebSocketMultiplayerPeer", WebSocketMultiplayerPeer::___get_type_tag(), WebSocketMultiplayerPeer::___get_base_type_tag());
	godot::_TagDB::register_global_type("ResourceImporterWebm", ResourceImporterWebm::___get_type_tag(), ResourceImporterWebm::___get_base_type_tag());
	godot::_TagDB::register_global_type("VideoStreamWebm", VideoStreamWebm::___get_type_tag(), VideoStreamWebm::___get_base_type_tag());
	godot::_TagDB::register_global_type("VisualScriptEditor", VisualScriptEditor::___get_type_tag(), VisualScriptEditor::___get_base_type_tag());
	godot::_TagDB::register_global_type("WebSocketServer", WebSocketServer::___get_type_tag(), WebSocketServer::___get_base_type_tag());
	godot::_TagDB::register_global_type("WebSocketClient", WebSocketClient::___get_type_tag(), WebSocketClient::___get_base_type_tag());
	godot::_TagDB::register_global_type("WebSocketPeer", WebSocketPeer::___get_type_tag(), WebSocketPeer::___get_base_type_tag());
	godot::_TagDB::register_global_type("BulletPhysicsServer", BulletPhysicsServer::___get_type_tag(), BulletPhysicsServer::___get_base_type_tag());
	godot::_TagDB::register_global_type("BulletPhysicsDirectBodyState", BulletPhysicsDirectBodyState::___get_type_tag(), BulletPhysicsDirectBodyState::___get_base_type_tag());
	godot::_TagDB::register_global_type("Physics2DServerSW", Physics2DServerSW::___get_type_tag(), Physics2DServerSW::___get_base_type_tag());
	godot::_TagDB::register_global_type("Physics2DDirectBodyStateSW", Physics2DDirectBodyStateSW::___get_type_tag(), Physics2DDirectBodyStateSW::___get_base_type_tag());
}

}