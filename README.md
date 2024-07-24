// How to run c++ Graphics program in Vs Code.
1) First Create a Folder In Desktop/in any.
2) Copy/Cut the graphics.h and winbgi file and paste into C://mingw//include and copy/cut library file and paste into C://mingw//lib.
3) Inside The Folder create a folder named as ".vscode" and inside the ".vscode" folder kept the "task.json" file.
4) Download exe runner and code runner,Goto to code runner setting.json file and int the c++ section paste the code -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32
5) Now you can run any cpp graphics program in vs code.
