# Vulnerable Website

Summary: A code example of how to log into http://testphp.vulnweb.com/login.php.

## Build
When cloning this repository, please use:
```
git clone --recurse-submodules https://github.com/Ashley1Jones/vulnerable_website.git
```
as to also clone submodule cpp-httplib.

### Build: Windows
The project was tested and built using Visual Studio 2022. 

Configure build with cmake:
```
cmake -S . -B ./build
```
Build the project:
```
cmake --build ./build --config Release
```
The vulnerable website executable should be in ./build/Release/vulnerable_website. To start you can double click executable or:
```
start ./build/Release/vulnerable_website
```

### Build: Linux
Sorry! This has not been tested for Linux, however, these are the commands I could see working:
```
cmake -DCMAKE_BUILD_TYPE=Release -S . -B ./build
```
Build the project:
```
cmake --build ./build
```
Make executable runnable:
```
sudo chmod +x ./build/Release/vulnerable_website
```
Run the executable:
```
./build/Release/vulnerable_website
```

## Note
"simple_request" branch has been preserved for extra visibility. 
