from binding_generator_hooks import BindingGeneratorHooks


class BindingGeneratorHooksExtension(BindingGeneratorHooks):
    def alter_engine_class_header(self, class_api, lines):
        signals = []
        if "signals" in class_api:
            for signal_api in class_api["signals"]:
                name = signal_api["name"]
                signal_constant = "\tstatic constexpr char SIGNAL_" + name.upper() + '[] = "' + name + '";'
                signals.append(signal_constant)
            try:
                idx = lines.index("public:") + 1
                for signal_const in signals:
                    lines.insert(idx, signal_const)
                    idx += 1
            except ValueError:
                print("no public keyword found, not adding signals")
        return lines
