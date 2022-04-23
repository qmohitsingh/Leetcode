//https://leetcode.com/problems/encode-and-decode-tinyurl/

public class Codec {
    public List<String> urls;
    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        if(urls == null){
            urls = new ArrayList<>();
        }
        urls.add(longUrl);
        return String.valueOf(urls.size()-1);
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
         if(urls == null){
            return "";
         }else{
             return urls.get(Integer.parseInt(shortUrl));
         }
    }
}
