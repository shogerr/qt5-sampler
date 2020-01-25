$Env:VCPKG_ROOT=""

cmake -S . -B build_new -G "Ninja" `
    -DCMAKE_CXX_COMPILER="cl.exe" `
    -DCMAKE_C_COMPILER="cl.exe" `
    -DQt5_ROOT="C:/qt/5.14.0/wasm_32" `
    -DVCPKG_ENABLE=NO `
    -WASM_ENABLE=YES

