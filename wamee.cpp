#include <cstdio>
#include <cstring>

const int MAX_N = 1000;
const int MAX_TOTAL = 3000;

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char words[3][MAX_N][4]; 
        char allWords[MAX_TOTAL][4]; 
        int freq[MAX_TOTAL] = {0}; 
        int totalWords = 0;

        for (int p = 0; p < 3; ++p) {
            for (int i = 0; i < n; ++i) {
                scanf("%s", words[p][i]);

                int found = -1;
                for (int j = 0; j < totalWords; ++j) {
                    if (strcmp(allWords[j], words[p][i]) == 0) {
                        found = j;
                        break;
                    }
                }

                if (found == -1) {
                    strcpy(allWords[totalWords], words[p][i]);
                    freq[totalWords]++;
                    totalWords++;
                } else {
                    freq[found]++;
                }
            }
        }

        int score[3] = {0};

        for (int p = 0; p < 3; ++p) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < totalWords; ++j) {
                    if (strcmp(words[p][i], allWords[j]) == 0) {
                        if (freq[j] == 1)
                            score[p] += 3;
                        else if (freq[j] == 2)
                            score[p] += 1;
                        break;
                    }
                }
            }
        }

        printf("%d %d %d\n", score[0], score[1], score[2]);
    }

    return 0;
}
