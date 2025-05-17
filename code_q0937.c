->link with youtube->https://www.youtube.com/watch?v=UbNU98fKV8o

  ->second one->https://www.youtube.com/watch?v=JRm0ybcPSFc

/*other java solution*/
  class Solution {
    public String[] reorderLogFiles(String[] logs) {
        if(logs.length == 0) return logs;
        List<String> letterLogs = new ArrayList<>(), digitLogs = new ArrayList<>();
        separateLettersDigits(logs, letterLogs, digitLogs);
        sortLetterLogs(letterLogs);
        return generateOutput(letterLogs, digitLogs);  
    }
    
    void separateLettersDigits(
        String[] input, 
        List<String> letterLogs, 
        List<String> digitLogs
    ) { 
        for(String log : input) {
            if(Character.isDigit(log.charAt(log.length()-1))){
                digitLogs.add(log);
            } else {
                letterLogs.add(log);
            }
        }
    }
    
    void sortLetterLogs(
        List<String> letterLogs
    ) {
        Collections.sort(letterLogs, new Comparator<String>() {
            public int compare(String o1, String o2) {
			    String s1 = o1.substring(o1.indexOf(" ") + 1);
			    String s2 = o2.substring(o2.indexOf(" ") + 1);
                
                return s1.equals(s2) ? o1.compareTo(o2) : s1.compareTo(s2);
            }
        });
    }
    
    String[] generateOutput(
        List<String> letterLogs, 
        List<String> digitLogs
    ) {
        String[] output = new String[letterLogs.size() + digitLogs.size()];
        for(int i = 0; i < letterLogs.size(); i++) {
            output[i] = letterLogs.get(i);
        }
        for(int i = letterLogs.size(); i < output.length; i++) {
            output[i] = digitLogs.get(i-letterLogs.size());
        }
        return output;  
    }
}

  

  /*Other C++ soluction*/
  class Solution {
private:
    string findKey(string &log) {
        int i = 0;
        string key = "";
        for(char &ch: log) {
            if(ch == ' ')
                break;
            key += ch;
        }
        return key;
    }
    string findContent(string &log) {
        int i = 0;
        while(i < log.size() && log[i] != ' ')
            i++;

        return log.substr(i);
    }
    bool isLetterLog(string &log) {
        return log[log.size() - 1] >= 'a' 
                && log[log.size() - 1] <= 'z';
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs;
        // O(N)
        for(string &log: logs) {
            if(isLetterLog(log)) 
                letterLogs.push_back(log);
        }

        // O(NLogN ∗ L)
        sort(letterLogs.begin(), letterLogs.end(),
        [&](string &a, string &b) {
            string contentA = findContent(a);
            string contentB = findContent(b);
            if(contentA == contentB) 
                return findKey(a) < findKey(b);
            else 
                return contentA < contentB;
        });

        // O(N)
        vector<string> res;
        for(string &letterLog: letterLogs) 
            res.push_back(letterLog);

        // O(N)
        for(string &log: logs) {
            if(!isLetterLog(log))
                res.push_back(log);
        }

        return res;

    }
};

---------------my C++ solution--------------

class Solution {
private:
   bool isLetter(string &logA)
   {
      if((logA[logA.size()-1]>='a')&&(logA[logA.size()-1]<='z'))
      {
         return true;
      }
      return false;  
   }

   string findContent(string &log)
   {
      int i=0;
      while(i<log.size()&&log[i]!=' ')
      {
         i++;
      }
      return log.substr(i);  
   }

   string findKey(string &log)
   {
     string key="";
     for(char &ch:log)
     {
        if(ch==' ')
        {
            break;
        }
        key+=ch;
     }
     return key;
   }

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLog;
        for(string &log:logs)
        {
            std::cout<<"log "<<log<<std::endl;
            if(isLetter(log))
            {
               letterLog.push_back(log);
            }
        }

        // std::string temp="dig1 8 1 5 1";
        // string ContentA=findContent(temp);
        // cout<<"ContentA "<<ContentA<<endl;

        // string testTemp=findkey(temp);
        // cout<<"testTemp"<<testTemp<<endl;

    int counter=0;
    std::sort(letterLog.begin(),letterLog.end(),[&](string a,string b)
    {
        std::string contentA=findContent(a);
        std::string contentB=findContent(b);
        cout<<"counter "<<counter<<endl;
        cout<<"contentA "<<contentA<<endl;
        cout<<"contentB "<<contentB<<endl;
        counter++;

        if(contentA==contentB)
        {
            bool boolTemp=findKey(a)<findKey(b);
            std::cout<<"boolTemp "<<boolTemp<<endl;
            return boolTemp;
        }
        else{
             bool boolTemp2=contentA<contentB;
            std::cout<<"boolTemp2 "<<boolTemp2<<endl;
            return boolTemp2;
        }
        return true;
    }
    );

     vector<string> res;
        for(string &letterLog_ind: letterLog) 
            res.push_back(letterLog_ind);


       for(string &log:logs)
       {
            if(!isLetter(log))
            {
               res.push_back(log);
            }
        }

        return res;
        // return letterLog;
    }
};
