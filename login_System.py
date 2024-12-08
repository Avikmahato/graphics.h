import os
import getch
from colorama import Fore,Back
def reset(nameId):
    check=open('userlist.txt','r')
    if nameId not in check.read():
        print(Fore.RED+"You Don't Have Any Account"+Fore.RESET)
        check.close()
        return
    data=open("Users//"+nameId+'.txt','r')
    uname=input(Fore.LIGHTGREEN_EX+"Enter Your Username : "+Fore.RESET)
    if data.readline().strip() !=uname:
        print(Fore.RED+"You Don't Have Any Account."+Fore.RESET)
    else:
        data.readline().strip()
        fname=data.readline().strip()
        roll=data.readline().strip()
        address=data.readline().strip()
        collage=data.readline().strip()
        data.close()
        put=open("Users//"+name+'.txt','w')
        passw=input(Fore.LIGHTBLUE_EX+"New Password : "+Fore.RESET)
        rpassw=input(Fore.LIGHTBLUE_EX+"Re-Enter New Password : "+Fore.RESET)
        if passw==rpassw:
            put.write(uname)
            put.write('\n')
            put.write(passw)
            put.write('\n')
            put.write(fname)
            put.write('\n')
            put.write(roll)
            put.write('\n')
            put.write(address)
            put.write('\n')
            put.write(collage)
            put.close()
        else:
            print(Fore.RED+"Password Doesn't Match."+Fore.RESET)
def login(nameId):
    check=open('userlist.txt','r')
    if nameId not in check.read():
        print(Fore.RED+"You Don't Have Any Account.")
        check.close()
        return
    forread=open("Users//"+nameId+'.txt','r')
    uname=input(Fore.YELLOW+"Username : "+Fore.RESET)
    passw=input(Fore.YELLOW+"Password : "+Fore.RESET)
    if uname==forread.readline().strip() and passw==forread.readline().strip():
        os.system('cls')
        print(Fore.WHITE+Back.RED+"****************User Details*****************"+Back.RESET+Fore.RESET)
        print(Fore.GREEN+"Student Name :"+Fore.BLUE+forread.readline().strip()+Fore.RESET)
        print(Fore.GREEN+"Student Roll :"+Fore.BLUE+forread.readline().strip()+Fore.RESET)
        print(Fore.GREEN+"Address :"+Fore.BLUE+forread.readline().strip()+Fore.RESET)
        print(Fore.GREEN+"Collage :"+Fore.BLUE+forread.readline().strip()+Fore.RESET)
        exit(0)
    else:
        print(Fore.RED+"Login failed."+Fore.RESET)
        print(Fore.LIGHTGREEN_EX+"Press 1 For Retry And 2 For Reset Password."+Fore.RESET)
        op=getch.getch()
        if op==b'1':
            login(nameId)
        else:
            reset(nameId)
def register():
    name=input(Fore.YELLOW+"Enter Your Id-First Name : "+Fore.RESET)
    name=name.capitalize()
    check=open('userlist.txt','r')
    if name in check.read():
        print(Fore.LIGHTCYAN_EX+"You already have an account.Please Log in"+Fore.RESET)
        check.close()
        return
    main=open('userlist.txt','a')
    main.write("\n"+name)
    main.close()
    forwrite=open("Users//"+name+".txt",'a')
    usrnm=input(Fore.GREEN+"Username : "+Fore.RESET)
    passw=input(Fore.GREEN+"Password : "+Fore.RESET)
    forwrite.write(usrnm)
    forwrite.write('\n')
    forwrite.write(passw)
    forwrite.write('\n')
    forwrite.write(input(Fore.GREEN+"Enter Your Full Name : "+Fore.RESET))
    forwrite.write('\n')
    forwrite.write(input(Fore.GREEN+"Enter Your Roll Number : "+Fore.RESET))
    forwrite.write('\n')
    forwrite.write(input(Fore.GREEN+"Enter Your Address : "+Fore.RESET))
    forwrite.write('\n')
    forwrite.write(input(Fore.GREEN+"Enter Your Collage : "+Fore.RESET))
    forwrite.close()
    os.system('cls')
while True:
    print(Fore.GREEN+"(1) Login  "+Fore.RESET)
    print(Fore.GREEN+"(2) Register "+Fore.RESET)
    print(Fore.GREEN+"(3) Reset "+Fore.RESET)
    print(Fore.GREEN+"(4) Exit"+Fore.RESET)
    print(Fore.CYAN+"Choose A Option : "+Fore.RESET,end='')
    op=getch.getch()
    os.system('cls')
    match(op):
        case b'1':
            name=input(Fore.BLUE+"Enter Your Id-First Name : ")
            login(name)
        case b'2':
            register()
        case b'3':
            name=input(Fore.MAGENTA+"Enter Your Id-First Name : "+Fore.RESET)
            reset(name.capitalize())
        case b'4':
            exit(0)