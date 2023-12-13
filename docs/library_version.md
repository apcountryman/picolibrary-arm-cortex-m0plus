# Library Version
To access the null-terminated library version string that is stored in ROM, link with the
`picolibrary-arm-cortex-m0plus-version` static library, include
[`picolibrary/arm/cortex/m0plus/version.h`](https://github.com/apcountryman/picolibrary-arm-cortex-m0plus/blob/main/include/picolibrary/arm/cortex/m0plus/version.h)
and use `::picolibrary::Arm::Cortex::M0PLUS::version()`:
```cmake
target_link_libraries(
    foo
    picolibrary-arm-cortex-m0plus
    picolibrary-arm-cortex-m0plus-version
)
```
```c++
#include "picolibrary/stream.h"
#include "picolibrary/arm/cortex/m0plus/version.h"

void foo( ::picolibrary::Reliable_Output_Stream & stream ) noexcept
{
    stream.put( ::picolibrary::Arm::Cortex::M0PLUS::version() );
}
```
The null-terminated library version string is populated with the output of the following
Git command:
```shell
git describe --match=none --always --dirty --broken
```
