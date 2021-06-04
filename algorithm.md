# Password Hashing  
  
# Overview  
The idea is to create a login and create account system for a user. When a user creates an account, the password gets hashed and put into a hashtable as the hashed value. When a user logs in, the password gets hashed again, and the hashed value gets checked against the value at the location in the hash table. To avoid collisions, we should attempt to use separate chaining methods (Linked-Lists).  
  
## Classes & Methods  
---------------------------------------------------------------  
### Account  
---------------------------------------------------------------  
  
### Overview  
create an account that the user can use to log in and out of some system.  
  
### Methods  
  
#### generateSalt() (protected)  
  
##### Goals  
The goal of this method is to generate a random 'salt' of 16-bits in length  
  
##### Input  
N/A  
  
##### Output  
int  
  
##### Steps  
For i = 0  and less that 16, randomly choose a 0 or 1 and add multiply it by a power of 2 and add it to existing int. Once finished, return that int.  
  
#### getSalt  
  
##### Goals  
The goal of this method is to return the salt  
  
##### Input  
N/A  
  
##### Output  
int    
  
##### Steps  
return salt  
  
#### isBanned  
  
##### Goals  
return if this user is banned or not  
  
##### Input  
N/A  
  
##### Output  
bool  
  
##### Steps  
return banned member  
  
#### getBanTime  
  
##### Goals  
The goal is to get the ban time length  
  
##### Input  
N/A  
  
##### Output  
int  
  
##### Steps  
return banTime member  
  
---------------------------------------------------------------  
### Admin  
---------------------------------------------------------------  
  
### Overview  
Create an admin account that can have other features than a regular account. This class doesn't do much.    
  
---------------------------------------------------------------  
### Menu  
---------------------------------------------------------------  
  
### Overview  
Create a user interactable menu and create methods that reflect the options on the menu  
  
### Methods  
  
#### createAccount()  
  
##### Goals  
The goal of this is to create a new account  
  
##### Input  
N/A  
  
##### Output  
void  
  
##### Steps  
This method is called via a menu. When called, ask person to enter username. Once they do that, ask them to enter password (which is hidden by turning echo off with ubuntu cmd), ask them to re-enter password. Make sure that the username is unique by calling isUnique. If the first password and the re-entered one match, create the account by calling the Account(username) constructor, then hash the password and store the hashed password, username, and the salt in a hashtable at the hashed passwords base-10 value.  
  
#### login  
  
##### Goals  
The goal of this is to let the user log in to their account. If the log in is successful, we'll inform the user, if not we'll inform the user that either the username or password is incorrect.  
  
##### Input  
N/A  
  
##### Output  
void  
  
##### Steps  
Ask the person for their username, then ask for their password. If either the username is incorrect, or the hashedpassword doesn't match the one in the table, well inform the person that either the username or password is incorrect (we won't specificy which). If both correct but user is banned, inform them that they can't login. When login is successful: if user is just a regular account, print "Login successful" and then exit. If the user is an admin, call the admin menu.  
  
#### isUnique  
  
##### Goals  
The goal of this method is to check if a username is unique  
  
##### Input  
string  
  
##### Output  
bool  
  
##### Steps  
take the string, and compare it to the usernames of accounts in linked list. If the username already exists, return false, otherwise return true.  
  
#### banUser  
  
##### Goals  
Deny access of a user to their account from some period of time  
  
##### Input  
string, int  
  
##### Output  
void  
  
##### Steps  
first make sure that the user with the username string actually exists, if they do change their banned value to true and banTime to int.  
  
#### deleteUser  
  
##### Goals  
The goal is to completely delete a user  
  
##### Input  
string  
  
##### Output  
void  
  
##### Steps  
Must put in username and password of user that you want to delete. go to user in LL and change the node before them to point to the one after. Then use the password and info from username to find the user in the hashtable and remove them from the hashtable  
  
#### unbanUser  
  
##### Goals  
Remove ban from user so they can access their account  
  
##### Input  
string  
  
##### Output  
void  
  
##### Steps  
Check if user is banned, if they are, unban them (banned = false). Otherwise, do nothing.  
  
---------------------------------------------------------------  
### Hash  
---------------------------------------------------------------  
  
### Overview  
Create a class that handles a hash function to hash a password  
  
### Methods  
  
#### hashFunction  
  
##### Goals  
The goal of this is to use all given information to hash our password into a unique password  
  
##### Input  
strings  
  
##### Output  
string  
  
##### Steps  
First convert each character of password to an ascii value times it's position+1 (can't use 0 because then you could change the first letter and still get same hash) and add them all together. This keeps information about not only about the location of each character in the string, but also it's casing. Next add the salt to this new numerical password as well as the ascii of the username. Now based on my research (and a helpful video by computerphile), we are going to run a loop 80 times. During different segements of the loop we should do different things. So first we are going to have values called a, b, c, d, and e. In each segment we are going to do different bitwise operations to try to 'psuedo'randomly 'mix' our values up. Initially a = h0, b=h1, c=h2, d=h3, e = h4. I'll be following the sha 1 algorithm here which goes like this. For 0->19, f = (b&c)|((~b)|d), 20-39 f = b^c^d, 40-59 f = (b&c)|(b&d)|(c&d), then for the last loop we repeat the second loop. We also have a value k that's just a fixed number depending on which segment we're in. At the end we add the new states to the original states, and then add them all together and return the hex value.
