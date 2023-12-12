# Usage

## Table of Contents
1. [Dependency](#dependency)
    1. [Configuration Options](#configuration-options)
1. [Development](#development)

## Dependency
To use picolibrary-arm-cortex-m0plus as a dependency, simply add the subdirectory
containing the repository to a CMake build, and link with the
`picolibrary-arm-cortex-m0plus` static library.
```cmake
add_subdirectory( picolibrary-arm-cortex-m0plus )
```
```cmake
target_link_libraries(
    foo
    picolibrary-arm-cortex-m0plus
)
```

The `picolibrary-arm-cortex-m0plus` static library does not include
`::picolibrary::Arm::Cortex::M0PLUS::version()`.
To use `::picolibrary::Arm::Cortex::M0PLUS::version()`, link with the
`picolibrary-arm-cortex-m0plus-version` static library.
```cmake
target_link_libraries(
    foo
    picolibrary-arm-cortex-m0plus
    picolibrary-arm-cortex-m0plus-version
)
```

### Configuration Options
picolibrary-arm-cortex-m0plus supports the following project configuration options:
- `PICOLIBRARY_ARM_CORTEX_M0PLUS_USE_PARENT_PROJECT_PICOLIBRARY` (defaults to `ON`): use
  parent project's picolibrary

## Development
The repository's Git `pre-commit` hook script is the simplest way to configure, and build
picolibrary-arm-cortex-m0plus during development.
See the `pre-commit` script's help text for usage details.
```shell
./git/hooks/pre-commit --help
```

Additional checks, such as static analysis, are performed by the repository's GitHub
Actions CI workflow.
