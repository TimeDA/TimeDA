#include<cstdio>
 #include<cstdlib>
 #include<vector>
 #include<string>
 #include<sstream>
 #include<iostream>
 #include<algorithm>
 #include<map>
 
 using namespace std;
 
 int best;
 int n;
 int wcount;
 map<string,int> wordmap;
 vector<string> words;
 vector<vector<int> > sentences;
 bool eng[30];
 vector<bool> isOEng;
 vector<bool> isOFra;
 
 void check()
 {
     vector<bool> isEng(wcount, false);
     vector<bool> isFra(wcount, false);
     int cand = 0;
     for (int i = 2; i < n; i++)
     {
         if (eng[i])
         {
             for (int j = 0; j < sentences[i].size(); j++)
             {
                 int a = sentences[i][j];
                 if (!(isOEng[a] || isEng[a]) && (isOFra[a] || isFra[a]))
                 {
                     cand++;
                 }
                 isEng[a] = true;
             }
         }
         else
         {
             for (int j = 0; j < sentences[i].size(); j++)
             {
                 isFra[sentences[i][j]] = true;
             }
         }
     }
 
 
     for (int i = 0; i < wcount; i++)
     {
         if ((isOEng[i] || isEng[i]) && (isOFra[i] || isFra[i]))
             
     }
     best = min(best, cand);
 }
 
 void rec(int pos)
 {
     if (pos == n)
     {
         check();
         return;
     }
     eng[pos] = false;
     rec(pos+1);
     eng[pos] = true;
     rec(pos+1);
 }
 
 int main()
 {
     int t, test;
     scanf("%d", &test);
     for (t = 0; t < test; t++)
     {
         words.clear();
         wordmap.clear();
         sentences.clear();
         scanf("%d\n", &n);
         char buffer[20000];
         for (int i = 0; i < n; i++)
         {
             gets(buffer);
             stringstream ss(buffer);
             string word;
             vector<int> sentence;
             while (ss >> word)
             {
                 int index = 0;
                 if (wordmap.count(word) != 0)
                 {
                     index = wordmap[word];
                 }
                 else
                 {
                     index = words.size();
                     words.push_back(word);
                     wordmap[word] = index;
                 }
                 sentence.push_back(index);
             }
             sentences.push_back(sentence);
         }
         wcount = words.size();
 
         vector<bool> isOrigEng(wcount, false);
         for (int j = 0; j < sentences[0].size(); j++)
         {
             isOrigEng[sentences[0][j]] = true;
         }
         isOEng = isOrigEng;
 
         vector<bool> isOrigFra(wcount, false);
         for (int j = 0; j < sentences[1].size(); j++)
         {
             isOrigFra[sentences[1][j]] = true;
         }
         isOFra = isOrigFra;
 
         best = wcount;
         rec(2);
 
         printf("Case #%d: %d\n", t+1, best);
     }
     return 0;
 }
