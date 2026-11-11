func lengthOfLongestSubstring(s string) int {
    n:=len(s)
    maxlen:=0
    i:=0
    mp:=make(map[byte]int)


    for j:=0;j<n;j++{
       mp[s[j]]++

       for mp[s[j]]>1{
        mp[s[i]]--

        if mp[s[i]]==0{
            delete(mp,s[i])
        }
        i++
       }

       currlen:=j-i+1

       if currlen>maxlen{
        maxlen=currlen
       }
        
    }
    return maxlen
}