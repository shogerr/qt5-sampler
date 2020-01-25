qt-sampler
==========


## Notes

### Starting Visual Studio

The following batch commands will start visual studio with the runtime dependencies met.
Ensure that the plug-in runtime libraries are not on the path from another Qt installation.

```
SET "QT_QPA_PLATFORM_PLUGIN_PATH=C:\Qt\5.12.1\msvc2017_64\plugins\platforms"

CD "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\IDE\"
START devenv.exe
```

