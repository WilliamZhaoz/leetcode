class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, v1, v2;
        while (i < version1.size() || j < version2.size()) {
            v1 = 0, v2 = 0;
            while (version1[i] != '.' && i < version1.size()) {
                v1 =  v1 * 10 + version1[i++] - '0';
            }       
            while (version2[j] != '.' && j < version2.size()) {
                v2 =  v2 * 10 + version2[j++] - '0';
            }
            if (v1 == v2) {
                i++; j++;
                continue;
            }
            return v1 > v2 ? 1 : -1;
        }
        return 0;
    }
};