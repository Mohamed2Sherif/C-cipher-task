#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <cctype>
using namespace std ;
// creating the alphabit array to loop through them 
// using vectors because it's like python list and easier for me to use 
// the idea in vector is that it's dynamiclly allocated inside the memory and not a fixed size like arrays
vector<char> alphabits ={'a','b','c','d','e','f','g','h','i','j',
'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
// make a reverse lsit of the alphabits 
vector<char> rever_alphabits = vector<char>(alphabits.rbegin(), alphabits.rend()); ;
vector<char> result ={} ;
string Encrypt(string,vector<char> = alphabits,vector<char> = rever_alphabits) ;
string Decrypt(string,vector<char> = alphabits,vector<char> = rever_alphabits) ;
int main()
{    

// make the user input the word to perform an action 
 string word ;
 int option ;
cout<<"Enter a string : ";
cin>>word;
// make the user choose an action 
cout<<"pick option : \n";
cout<<"1-Encrypt the word\n";
cout<<"2-Decrypt the word\n";
cin>>option;
// perform that action 
switch (option) {
        case 1 :
        // call the encrypt function
            cout<<Encrypt(word);
        break;
        case 2 :
            // call the decrypt function
            cout<<Decrypt(word);
            break;

        default :
            // print the ipnut was invalid  
            cout<<"that's not available option";
         break;
    
    }
    return 0 ;
}

string Encrypt(string text,  vector<char> lis1, vector<char> lis2 ) 
{
    // looping through the string that the user inputted 
for (int i= 0; i < text.length();i++)
            {
                // looping through the alphabit list and check if that string is there 
                for (int j=0 ; j < lis1.size();j++)
                {   
                    if (tolower(text[i])==lis1[j])

                    {
                        if (tolower(text[i]) == text[i])
                        result.push_back(lis2[j]);
                        else result.push_back(toupper(lis2[j]));
                    }
                    
                }
            }
            string final = std::accumulate(result.begin(),result.end(), std::string(""));
            return final;
}
string Decrypt(string text , vector<char> lis1,vector<char> lis2 ){

 for (int  i=0 ; i < result.size();i++){
            result.pop_back();
            //to avoid wasting memory space 
            result.shrink_to_fit();
            }
            
            for (int i =0 ; i < text.length();i++)
            {
                for (int j =0 ; j <lis2.size();j++)
                {
                    if (tolower(text[i]) == lis2[j])
                    {   
                        if (tolower(text[i])==text[i])
                        result.push_back( lis1[j]);
                        else result.push_back(toupper(lis1[j]));
                    }
                }
            }
            string final = std::accumulate(result.begin(),result.end(), std::string(""));
            return final;
}