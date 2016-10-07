========= How to set up a portsetter alias =========

1. nagivate to your /home directory (use cd .. OR ..)
2. type ls -a OR ls -al (to list all files in the directory)
3. click on .bash_aliases and select "open"
4. append the setport alias as such
        
        alias setport="./portsetter.cpp.o"
5. restart your terminal

From now on you should be able to simply type "setport -flag [PORT]..." into terminal.
NOTE: For an alias to work setport must be used in terminal.



========= How to run the test program =========

Simply run tests.cpp... 

Tests that should pass will return true and will print normally,
tests that should fail will return false and print out specific test error.

Expected output for test is as such...

    The initial general error... (generated from main)
    The usage... (generated from failing case or -h, --help, -?)
    The specific error (generated from the testcases)
