# ChickenSurvive
git clone git@github.com:Apr273/ChickenSurvive
cd ChickenSurvive
mkdir win32-build
cd win32-build
cmake .. -G"Visual Studio 16 2019" -A Win32
cd ..
cocos run -p win32
