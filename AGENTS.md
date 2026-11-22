# godot-cpp Header Documentation

## Project naming

- Name new project files in lowercase kebab-case, such as `file-name.ext`.
- Name new project folders in PascalCase, such as `FolderName`.
- Keep names required by tools or file formats, such as `project.godot`, `SConstruct`, and `.gitmodules`. Preserve names supplied by generators and external dependencies.

## Objective and scope

A request to follow this file means **deliver complete, verified documentation coverage for both handwritten and generated godot-cpp headers** in the selected API. Determine independently whether each tree is already complete, partially covered, or starting from scratch. Do this even when the request gives no status, starting point, or list of headers. The conditions in this file determine completion.

Paths below assume a project with a nested `godot-cpp` checkout. If the opened workspace is the godot-cpp checkout itself, resolve those paths from its root. An explicitly narrower request limits that run.

| Tree | Deliverable | Allowed source changes |
| --- | --- | --- |
| `godot-cpp/include/godot_cpp` | Markdown documentation for all applicable declarations in headers and include fragments | Documentation comments only. |
| `godot-cpp/gen/include` | The selected API's bindings with verified Markdown comments emitted by normal binding generation | The generator, versioned documentation inputs, and focused tests when needed. Generated C++ is produced through the generator. |

Preserve existing user changes and the normal API, build configuration, and behavior. Continue through all pending batches in the same session while authorized work remains.

Read and write files only inside the opened project. Keep snapshots, test translation units, generated validation files, logs, and temporary files there. Do not follow links outside the project or search other repositories, user profiles, or system temporary directories. If a step requires an external local tool or file, ask before using it. Give the exact path and explain what it is needed for. Continue independent work while waiting. Reuse explicit permission already granted for the same step.

## Resolve the Godot API version

Determine the actual API input before choosing documentation sources. Use the following order.

1. Honor an API version, API file, or build target explicitly selected by the user. Resolve that selection through the checkout's normal build and generator entry points.
2. Otherwise, identify the project's active or standard build target from its build scripts, presets, IDE tasks, or active build configuration. Trace its settings to the API metadata and interface inputs actually consumed by the binding generator. For example, SCons may use `custom_api_file` or `api_version`, and CMake may use `GODOTCPP_CUSTOM_API_FILE` or `GODOTCPP_API_VERSION`. Apply the checkout's precedence rules. A configured custom API file can override a version selector. Record the effective profile, precision, architecture, and generation options if they affect the emitted declarations.
3. If no active target selects an API, use the checkout's pinned default, if one exists. If the checkout has no default, look for a single unambiguous API input. A current generated version header can help identify that input when it matches the metadata and there is evidence that its output belongs to this build. If several targets remain equally plausible and choosing one changes the work, ask which target is intended and continue version-independent checks.

Read the release identity from the selected API JSON's `header` or the equivalent version metadata in that checkout. Use the full release identity, including major, minor, patch, and release status. Record the build or engine revision when available, especially for pre-release and custom builds. A filename or a major/minor selector alone gives incomplete release information. Treat version macros in generated headers as a cross-check. If they disagree with the resolved input, verify or regenerate the affected bindings before using them as references. The set of supported APIs, the installed engine version, and an old checkpoint do not determine the active API.

Select the official XML and engine sources for the resolved release or revision. For a custom API, use the source revision that produced the dump and verify custom declarations against its source and metadata. Keep documentation inputs and checkpoint evidence keyed to that release and input snapshot. If the exact source cannot be established or obtained, record the affected declarations as pending. Do not substitute a nearby release or the current `stable` or `latest` documentation channel.

## Determine what is complete

1. Review the working tree and existing Git changes for both trees, the generator, and documentation inputs. Use `git -C godot-cpp status --short` and `git -C godot-cpp diff -- include` in a nested checkout. Detect absent inputs, output, and checkpoints. Find or create the verified declaration register described below. Preserve staged and unstaged work. Save a project-local before-edit reference for every scope you change.
2. Resolve the API and generation configuration using the rules above. Make a declaration inventory for both trees. For handwritten headers, use C++ tooling where available and inspect raw source for inactive preprocessor branches, include fragments, and macros. For generated headers, use the selected API metadata, generator declaration sites, and a matching output tree. Include generated helpers, native structures, and interface declarations that do not appear as ordinary class members in the metadata. If matching output is absent, materialize it in project-local scratch when needed.
3. Match each declaration and parameter to its comment. Count unique source entities, with each overload covered separately. Document a declaration and its later definition once at the primary declaration, and cover a forward declaration on its own if it is the only declaration available. Treat macro expansions as uses of the defining macro. Inspect its behavior, generated declarations, and parameters at the definition.
4. Reconcile the current inventory with the verified declaration register and batch checkpoints against the completion conditions below. Verified register entries can replace repeated declaration review. A matching batch checkpoint can replace repeated validation for the exact scope it verifies. Confirm the API, configuration, relevant source and input hashes, covered declarations and output, documentation requirements, and recorded checks. When evidence is incomplete, audit only the part it leaves unverified. An existing comment, clean Git status, raw header count, or a successful compile alone is insufficient.
5. Make the completion decision independently for each tree. If both pass, report the verification and finish. If one passes, reuse it and complete the other. If neither passes, fill the gaps in both. Reuse correct comments, reviewed inputs, and confirmed batches. When no usable evidence exists, establish the baseline and verify the current checkout from scratch. An existing register or batch checkpoint is never a prerequisite to starting.
6. Work in small, reviewable batches. Automate declaration matching, parameter and enum coverage auditing, format checks, and deterministic generation where practical. Use targeted source review for semantics and edge cases. Prefer fixing a shared generator emission path when it would resolve a repeated gap safely. Keep reviewed inputs, the declaration register, and checkpoints under Git version control.

A tree is **complete** only when all applicable entities in its current inventory have one attached, verified Markdown comment, every required parameter has its own description, every public and protected API declaration has a meaningful `Used for` block, retained examples follow this file, and the checks below pass or have matching recorded evidence. A declaration whose required usage context cannot be verified stays pending. A generated declaration whose description or required detail cannot be verified also stays pending. Report missing sources and unavailable mandatory checks.

## Sources and accuracy

- Use the resolved API metadata for declaration identity and types. Match the exact class, member, overload, argument types, and result before reusing a description or example.
- Use exact-version official class-reference XML as the source for documented engine behavior. Prefer reviewed local inputs under the version-specific documentation directory. If needed, obtain the matching official copies through an authorized source and save them in the project for offline regeneration.
- Verify C++ behavior against the handwritten declarations and implementation, the matching generated bindings, and the engine source at the resolved revision when the binding alone leaves behavior unclear.
- Check GDScript and C# descriptions for language-specific behavior before adapting them. Use the C++ behavior, including verified boundary inclusion, coordinate frames, property accessor differences, value conversions, and ownership. Leave unverified claims pending.

## Verify what each declaration does

Describe the behavior of the declaration in the C++ header. For a getter, start with what the returned value means. For a setter, start with what it changes and say whether it clamps, rejects, or stores the input as supplied when that behavior matters. If another object or subsystem uses the value later, name that consumer and explain its effect in a separate sentence. Preserve useful details about the setting, including verified units, ranges, defaults, and conditions.

Treat a property description from the class-reference XML as source material for its accessors. Rewrite it to fit the getter or setter. Check the binding, the matching engine implementation, and the code that consumes the value when the description makes a claim about its effect. Verify which quantity is counted or measured and where limits are enforced. If the XML disagrees with the implementation, use the verified C++ behavior and record the discrepancy in the versioned documentation input. Leave any claim that still lacks evidence pending.

Apply this check to both new and existing comments. Fix generated comments through the generator or a reviewed, version-specific input, then regenerate. Recheck affected entries in the verified declaration register before reusing them.

## Coverage and format

Cover every meaningful declaration at every access level. Include classes, structs, unions and nested types, functions, methods, constructors, destructors, operators, callbacks, properties and their accessors, fields and static members, constants, enums and every enumerator, type aliases, templates, and macros. Describe internal members by their actual roles and call sites.

Write concise, natural English that makes sense in a VS Code Microsoft C/C++ IntelliSense hover. Use one documentation block immediately above the relevant declaration or its template introducer. Use `/** ... */` for primary blocks and `///` for short enumerator descriptions where appropriate. Keep the comment content in Markdown, including all new or revised generated comments. Replace inherited Doxygen directives such as `@brief`, `@param`, `@tparam`, `@return`, `@code`, and `@endcode` with prose, Markdown lists, or fenced code blocks. Format C++ names and values as inline code. Fully qualify references to other C++ API elements.

- Start with what the entity does or represents. Identify the actor, affected object, and owner of the result when relevant. For types, describe the state they control and their relationship to other objects. For values, fields, and constants, describe their meaning and effect.
- Add exactly one separate Markdown paragraph beginning with `**Used for**` to every public and protected API declaration in both trees. Place it after the behavior description and before parameter entries or examples. Cover each overload and externally accessible declaration at namespace or global scope. Describe a concrete, verified task the API helps with, a decision its result supports, or its role in an actual call path. For protected APIs, use the real extension, inheritance, or internal call context. The block must add information beyond the behavior description and the signature. Keep it short. If you cannot verify a meaningful use, record the declaration as pending.
- Give **every function, method, constructor, operator, callback, template, and macro parameter its own Markdown entry**. Use the declaration's exact parameter name. For an unnamed parameter, identify it unambiguously by position and type. Cover variadic packs and the parameters of each overload. Include input or output direction, valid ranges, units, coordinate space, nullability, lifetime, ownership, defaults and sentinel values where they matter. For an output, state what is written and when it is written or left unchanged. If a parameter is ignored in a verified branch, say so. Give its concrete role even if its name is clear.
- Explain the result, important side effects, conditions, and failure behavior when relevant. Distinguish related APIs by their actual semantics, including local and global coordinates, direct and inherited state, and reference and value behavior.
- Use the smallest practical vocabulary of common programming terms. Use the same word for the same operation throughout handwritten and generated comments. Repeating a precise word is better than varying it for style. Use a different term only when the distinction helps the reader understand the API. For example, use `create` when the operation produces a new object and the mechanism is irrelevant, `allocate` when obtaining storage matters, and `construct` when starting a C++ object's lifetime or running its constructor matters. Keep established C++ and Godot terms when they carry specific meaning.
- Keep sentences short. Avoid filler, tautologies, duplicated blocks, and general API advice. Mention an alternative only if its functionality is equivalent and its performance advantage has been verified. Use its fully qualified C++ name.

## C++ examples

Code examples are optional in both trees.

- For handwritten headers, **preserve existing examples and add no new examples** by default, including when starting from scratch. Verify an existing example when revising its surrounding description. Preserve its C++ content when only converting its formatting. Record any example that cannot be verified.
- For generated headers, preserve useful, verified C++ examples. Where a verified example is unavailable, emit the verified description and parameter entries.
- Use a fenced block marked `cpp` for every example. Show a common task and what the code does with the result. Introduce the minimum setup needed to identify objects, values, and arguments. Place the documented API use early when the setup allows it. For lifecycle methods, callbacks, and internal declarations, give the actual context and respect access restrictions. Verify surrounding types, methods, ownership, units, and coordinate systems. Explain essential Godot-specific helpers briefly. Use valid contextual snippets when a standalone translation unit would obscure the point.

## Generated documentation

Store the exact-version official XML, reviewed descriptions where required, and verified C++ examples as versioned local inputs under `godot-cpp/gdextension/header_docs/`. Regeneration must be reproducible offline. Treat API metadata as the source of declaration identity, not as prose or example content. The XML packed by `doc_source_generator.py` supplies runtime documentation. Header comments are a separate generator output.

Emit comments alongside the declarations as part of binding generation. Use one Markdown block per documented entity, including applicable classes, methods and overloads, enums and their values, fields, constants, templates, and other meaningful generated declarations. Use verified descriptions only. If a match, description, or required parameter detail cannot be verified, record the pending item and the missing evidence. Preserve independently verified prose where it can be emitted accurately. Leave ordinary generated C++ unchanged after stripping the documentation comments. Use the generator for all generated changes.

Use the checkout's normal binding generation entry point with the resolved API metadata, matching interface input, and effective generation options. Preserve any build profile or hooks that affect the selected declarations. Inspect the entry point in the current checkout before invoking it. If header comment support is absent, implement it in that generation pipeline. Pass the generator a fresh project-local scratch output directory. In checkouts where `binding_generator.generate_bindings` replaces `<output_dir>/gen`, never point a validation run at the existing build directory.

Use the matching generated include tree, including any interface headers required by the checkout, with the handwritten include tree for validation. When generated work is required, deliver the verified headers to the intended output through the regular generation workflow, preserving existing user changes. Keep unrelated build artifacts out of the deliverable. If regeneration needs an external interpreter, follow the permission rule above. A project-local archived interface can serve as a validation input after verifying its release and both API and interface inputs against the resolved target.

## Verification and completion

- Audit each batch for attached comments, all parameter names, enumerators, access levels, and inactive branches. For public and protected APIs, check that each `**Used for**` block adds a concrete, verified use distinct from the behavior description. Check every retained example for the intended entity and verified use. Test the hover format or inspect attachment directly when editor tooling is unavailable.
- Run `git -C godot-cpp diff --check -- include` for handwritten changes. Compare the before and after files after removing documentation comments alone. Preserve licenses, non-documentation comments, whitespace, line endings, signatures, macro bodies and continuations, includes, access levels, implementations, and behavior.
- Run a C++17 syntax check against the selected API and generated bindings, with each header in its supported include context and fragments included through their owners. Check the project configuration and relevant alternate branches, including threaded debug and development configurations where the checkout and authorized toolchain support them. Report the actual files and configurations checked.
- When generated verification needs fresh evidence, run the focused documentation version-selection test in `godot-cpp/test/test_header_documentation.py` or the equivalent for the checkout. Add that focused test as part of a new documentation emitter if it is missing. Run the other focused tests that exercise the changed generator behavior. Regenerate twice from the same inputs and compare the outputs byte for byte. Compare against a documentation-free baseline from the same API and generator settings after stripping only the emitted documentation comments. Check C++17 syntax. Skip the full cross-version compatibility suite when the generated C++ comparison confirms comment-only differences.
- Every 10 minutes during sustained work, report the number of declarations verified, the number remaining or the best measured estimate, elapsed time, and the estimated time remaining. Separate the count of edited comments from verified coverage. Continue after the update.
- Before finishing, report the completion decision for each tree, verified and pending declaration counts, sources, checks and configuration, and specific blockers. State which checks were reused from matching evidence. Claim completion or successful compilation only for what was verified.

## Verified declaration register

Find and reuse the project-local, Git-tracked register of declarations whose documentation meets the current rules. If no register exists, create `godot-cpp/gdextension/header_docs/verified_declarations.json`. Use the same register for handwritten and generated headers. An absent or empty register means there is no reusable declaration-level evidence yet. Start the audit and build it as you work.

- Identify each entry by its header path, fully qualified declaration, and exact C++ signature where applicable. List overloads separately. Include the preprocessor condition when distinct declarations share an identity across branches.
- Record the selected API and generation configuration, the source revision or relevant input fingerprints, the verified comment fingerprint, and the revision of the documentation rules used for review. Record the checks or reference the batch record that contains them. Shared evidence may be stored once and referenced by multiple entries.
- Compare the current inventory against the register at the start of each run. Reuse an entry only when its declaration, comment, relevant inputs, and applicable rules still match. Review stale or missing entries and update the register as each batch is verified. When inputs or rules change, recheck the entries affected by that change.
- Add a declaration to the verified register only after checking its description, every parameter, comment placement, and any applicable `Used for` block and examples against the current rules. A header-level count or a successful build cannot establish declaration-level coverage on its own. Keep pending work in the batch records and use the verified entries to count actual coverage.

## Verification records

Look for a generated verification record at `godot-cpp/gdextension/header_docs/checkpoint.json` and any tracked handwritten verification record in the checkout. These files may be absent, partial, or stale. Use only the assertions their evidence supports.

Update these batch records alongside the declaration register. Keep them outside `gen`. Record the selected API and configuration, the verified scope by header or declaration, source revisions or input and output fingerprints, the documentation requirements checked, the commands and results, and any pending items. Record enough information to tell whether a later source, generator, input, or rule change affects a given batch. Store reviewed source inputs locally so generation can run offline.
