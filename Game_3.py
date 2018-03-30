main_array=[1,2,3,4,5,6,7,8,9]              #The Group Of All Available Numbers.

#Define The Function 
def Game():
    
    used_array=[]       #The Group of All numbers That Will be used over players turns.
    array1=[]           #Player 1 Numbers.
    array2=[]           #Player 2 Numbers.
    while(len(used_array)<9):   #To Give Players 9 Turns .
        print("\n")
        if(len(used_array)!=0): #To not display empty array.
            print("The Used Numbers are ",used_array)   #to display used used numbers for each player.
        if(len(array1)!=0):
            print("Player 1 Your Numbers Are ",array1)
        print("Player 1 Enter A Number")    #player 1 Turn
        while(True):    #Because we didn't know how many times we will loop to be free up of mistakes.
            temp=int(input())   #Take The Number From Player 2
            if(temp>9 or temp<1):   #To Make Sure That The Playe Will Enter A number Between 1 and 9.
                print("Please Enter A Number Between 1 and 9")
                continue
            if(temp in used_array): #To Make Sure That The Player Will Not Enter A Used Number.
                print("Please Enter A non Used Number")
            else:
                used_array.append(temp) #ADD The Number To The Used Numbers List.
                array1.append(temp) #ADD The Number To Player 1 Numbers.
                break
        if(len(array1)>=3):  #To Start Look For Winning Number When The Player Have 3 Numbers At Least.
            for i in range(0,len(array1)):
                for j in range(0,len(array1)):
                    if(i==j):
                        j=j+1
                    else:    
                        for k in range(0,len(array1)):
                            if(k==i):
                                k=k+1
                            if(k==j):
                                k=k+1
                            if(k==len(array1)):
                                break
                            if(array1[i]+array1[j]+array1[k]==15):
                                print(array1[i],array1[j],array1[k],array1[i]+array1[j]+array1[k])
                                return("Player 1 Is The Winner"); #To Stop The Game When The Winner Is Found.
        
        if(len(used_array)==9): #To Stop The Game When The Nine numbers Are All Used.
            break
        print("\n")
        print("The Used Numbers are ",used_array)
        if(len(array2)!=0):
            print("player 2 Your Numbers are ",array2)
        print("Player 2 Enter A Number")
        while(True):
            temp=int(input())   #Take The Number From Player 2
            if(temp>9 or temp<1):   #To Make Sure That The Playe Will Enter A number Between 1 and 9.
                print("Please Enter A Number Between 1 and 9")
                continue
            if(temp in used_array): #To Make Sure That The Player Will Not Enter A Used Number.
                print("Please Enter A non Used Number")
            else:
                used_array.append(temp) #ADD The Number To The Used Numbers List.
                array2.append(temp) #ADD The Number To Player 2 Numbers.
                break
        if(len(array2)>=3): #To Start Look For Winning Number When The Player Have 3 Numbers At Least.
            for i in range(0,len(array2)):
                for j in range(0,len(array2)):
                    if(i==j):
                        j=j+1
                    else:    
                        for k in range(0,len(array2)):
                            if(k==i):
                                k=k+1
                            if(k==j):
                                k=k+1
                            if(k==len(array2)):
                                break
                            if(array2[i]+array2[j]+array2[k]==15):
                                print(array2[i],array2[j],array2[k],array2[i]+array2[j]+array2[k])
                                return("Player 2 Is The Winner"); #To Stop The Game When The Winner Is Found.
    return("Draw")

#Call The Function Game.
print(Game())
while(True): #Ask If The User Want to Play Again.
    try_again=str(input("Play Again(yes or no)"))
    if(try_again=="yes" or try_again=="Yes"):
        print(Game())
    elif(try_again=="no" or try_again=="No"):
        break
    else:
        print("Please Enter A Clear Order")
print("Thank You For Playing Come Back Later")
