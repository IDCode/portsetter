# portsetter
**========= How to set up a portsetter alias =========**

1. nagivate to your /home directory (use cd .. or ..)
2. type ls -a (to list all files in the directory)
3. click on .bash_aliases and select "open"
4. append the setport alias as such
        alias setport="./portsetter.cpp.o"
5. restart your terminal

From now on you should be able to simply type "setport -flag [PORT]..." into terminal.




**========= How to run the test program =========**

tests.cpp will run over hardcoded tests, it may not cover everything but it covers a large portion.
Expected output is as such...



   The initial general error... (generated from main)
   The usage... (generated from each failing case or -h, --help)
   The specific error (generated from the testcases)
