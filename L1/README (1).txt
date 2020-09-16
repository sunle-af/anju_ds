why we are using std::cin>> or std::sout<< insted of using just cin>> and cout>>
The std namespace is acronym for the word "standard." The built in C++ library routines are kept in the standard namespace.Standard namespace includes stuff like cout, cin etc. Because these are used very often, it reduces a lot of typing to add "using namespace std" at the top of your source code so that you won't have to type the std:: prefix constantly. And because these functions or more precisely objects are kept in a namespace, if you really want to use "vector" as a variable name, you still can as Namespaces give you more freedom to use short, accurate names.
Ese hi faltu mai agar tumhe upar using namespace std nahi use kara hai to use std:: agar kar liya hai to just use cout or cin EASY
L1
Obvisouly quick sort is the alogrithm for O(nlogn) complexity 
ab dekho kya hai ki ye jo bhi programs hai vo generalised hai iska matalb hia ki tum unhe kisi bhi value k liye use kar sakte ho. 
Jese kabhi kabhi GFG(geeks for geeks pe jo program hote hai vo specific value ya array pe hi kaam karte hai)
eg if you search for quicksort program then to website show karti hai usme ek array phele se hi bana hua hai but question kya hai vo to diffrent hai naa apana to isiliye apan usko generalised kar dete hai
taaki koi bhi kisi bhi value pe program run kar paye.
why we are using vector insted of arrays.
I don't know up to now I feel that using vector is a good thing isme jada mehnat nahi lagti hai or ye resizeable arrays nahi hote hai.

int input;
cin>>input;
arr.push_back(input); 
so iska matablb hota hai ki we made something called as input then we take the value entered by user and store it into input and last line meaning is that we push it back to arr(vector name) 
see let say there we want to insert 1 2 3 4
so what happenns is it first it is empty then we push back 1 after this we agian push back 2 and so on 
AND ALWAYS REMBEMBER for any search alogo. always the input should be in soted order always.

5.question
basically question is how can we use binary search method for improving the insetrion sort algo.
the number in left are sorted and on right are un sorted 
1348756(read about insertion sort little bit.
insertion sort alog worst case is n^2(n square)
so basically there must be a way in order to this efficiently.
Yeah we actually have it how ? we know that on the left there is sorted array so we can use it to search and put the number in correct place.
but in then it still is not good. but just an optimization.
