if (!$Env:VCPKG_ROOT) {
  Write-Error 'Please provide $Env:VCPKG_ROOT' -ErrorAction Stop
}

if (!(Get-Command cl.exe -ErrorAction SilentlyContinue)) {
  Write-Error 'Please run from a VS Development Environment.' -ErrorAction Stop
}

cmake -S . -B build_new -G "Ninja" `
    -DCMAKE_CXX_COMPILER="cl.exe" `
    -DCMAKE_C_COMPILER="cl.exe" `
    -DVCPKG_TARGET_TRIPLET=x64-windows `
    -DQt5_ROOT="C:/qt/5.14.0/msvc2017_64" `
    -DVCPKG_ENABLE=NO
