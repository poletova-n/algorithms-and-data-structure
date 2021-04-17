//Task 1.4.1 

//programm work with English texts
//texts should be in one-line format (look examples further)
//texts should end with one space(" ")
//programm can work with most of punctuation marks, but this apostrophe "’" must be changed to that "'" (i can try to fix it if necessary)
//after every punctuation marks(except dots in three dots in the end of a sentence) should be one space (even after '.' / '!' / '?' in the end of a sentences)
//programm work with contractions, so "have" is "'ve" | "will/shall" is "'ll | "not" is "n't" 
//also such contractions as from "is" to "'s" // from "are" to "'re" // from "am" to "'m" appear in the dictionary like "be"
//abbreviations stay in capital letters

//Examples of texts (you can copy-paste them in console):
//"you'll English texts for beginners to practice reading and comprehension online and for free can't. Practicing your comprehension of written English will both improve your vocabulary and understanding of grammar and word order. The texts below are designed to help you develop while giving you an instant evaluation of your progress. Prepared by experienced English teachers, the texts, articles and conversations are brief and appropriate to your level of proficiency. Take the multiple-choice quiz following each text, and you'll get the results immediately. You will feel both challenged and accomplished! You can even download (as PDF) and print the texts and exercises. "
//"My heart's in the Highlands, my heart is not here; My heart's in the Highlands, a chasing the deer; A chasing the wild deer, and following the roe, My heart's in the Highlands wherever I go. Farewell to the Highlands, farewell to the North, The birth-place of valour, the country of worth; Wherever I wander, wherever I rove, The hills of the Highlands for ever I love. Farewell to the mountains high covered with snow; Farewell to the straths and green valleys below; Farewell to the forests and wild-hanging woods; Farewell to the torrents and loud-pouring floods. "
//"Now that you've made the decision to learn English and are getting further in touch with the language, you can confirm that studying the English language is like living an exciting adventure. To make this learning path even more interesting, dare to add a component that will allow you to open the door to a universe full of knowledge, stories, and emotions: reading. You may think that reading in English is restricted to following a textbook that's quite difficult to understand. Don't worry! It doesn't have to be that way. If you choose the right study method, you'll be able to access a wide variety of texts in English for beginners that will help you improve your language skills in an enjoyable way. The innovative Smart Learning method, developed by ABA English according to the pedagogies from universities like Cambridge and the levels established by the CEFR, is the best option for you. Even though reading is an activity that you do very naturally and frequently in your mother tongue, you may think that it's better to learn English using other resources and formats. But if you want to be able to function better in different environments where the English language is used, having a reading habit is indispensable. This is the only way to build a solid foundation and acquire the necessary knowledge to reach the intermediate level. This doesn't mean that you have to make a superhuman effort to try to decipher difficult and extensive passages, where complex grammatical structures and terms are handled that are completely unknown to you. Not at all! You can start with short texts in English for beginners about things that you like, that you can understand without complications, and that keep you motivated to keep moving forward. "

//firstly printing number of words in the text
//secondly printing dictionary in alphabetical order with repeat count of each word
//in the end there will be 3 most repeated words
#include "binarySearchTree.h"
std::string takeWord(std::string& string); //taking word out of text
int wordCount = 0;

int main()
{
  std::string str;
  std::getline(std::cin, str);
  for (int i = 0;i<str.length();i++)
  {
    if (str[i] == ' ')
    {
      wordCount++;
    }
  }
  BinarySearchTree<int> tree;
  for (int i = 0;i < wordCount;i++)
  {
    tree.insert(takeWord(str));
  }
  tree.deleteKey("");
  std::cout <<"\nNumber of Words: " <<wordCount << "\n\n";
  tree.iterativeInorderWalk();
  tree.mostRepeated();
}

std::string takeWord(std::string& string)
{
 std::string temp(string.length(),' ');
 int j = 0;
 for (int i = 0;string[i] != ' ';i+=0)
 {
   if (string[i] == 39)
   {
     break;
   }
   temp[j] = string[i];
   string.erase(i, 1);
   j++;
 }
 string.erase(0, 1);
 for (int i = 0;temp[i] != ' ';i++)
 {
   temp.erase(j, temp.length() - j-1);
 }
 temp.erase(j, 1);
 for (int i = temp.length();i > -1;i--)
 {
   if ((('a' > temp[i] || 'Z' < temp[i]) && ('z' < temp[i] || 'A' > temp[i])) && temp[i] != 39 && temp[i] != 45)
   {
     temp.erase(i, 1);
   }
 }
 for (int i = 0;i < temp.length();i++)
 {
   if ('A' <= temp[i] && 'Z' >= temp[i])
   {
     int capitalLettersCount = 0;
     for (int j=0;j < temp.length();j++)
     {
       if ('A' <= temp[j] && 'Z' >= temp[j])
       {
         capitalLettersCount++;
       }
     }
     if (temp.length() == 1)
     {
       temp[i] = temp[i] + 32;
     }
     else if (capitalLettersCount != temp.length())
     {
       temp[i] = temp[i] + 32;
     }
   }
 }
 if (temp == "ve")
 {
   temp = "have";
   wordCount++;
 }
 if (temp == "s" || temp == "re" || temp == "been" || temp == "m")
 {
   temp = "be";
   wordCount++;
 }
 if (temp == "ll")
 {
   temp = "will";
   wordCount++;
 }
 if (temp[temp.length()-1] == 'n' && string[0] == 't' && ((string[1] == ' ' || string[2] == ' ')&&string[1]!='o'))
 {
   std::string NOTLine = "no";
   if (temp == "doesn" || temp == "didn" || temp == "don")
   {
     temp = "do";
   }
   else if (temp=="couldn")
   {
     temp = "can";
   }
   NOTLine = NOTLine + string;
   string = NOTLine;
   wordCount++;
 }
 return temp;
}
