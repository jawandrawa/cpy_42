char *solution(char *S) {
    int occurrences[26];
    for (int i = 0; i < 26; i++) {
        occurrences[i] = 0;
    }

    int len = strlen(S);
    for (int i = 0; i < len; i++) {
        occurrences[S[i] - 'a']++;
		printf("%d\n", occurrences[0]);
    }

    char best_char = 'a';
    int best_res = 0;

    for (int i = 1; i < 26; i++) {
        if ((occurrences[i] > best_res) || (occurrences[i] == best_res && best_char > i +  'a')) 
		{
				best_char = 'a' + i;
            best_res = occurrences[i];
        }
    }

    char *result = (char *)malloc(2 * sizeof(char));
    result[0] = best_char;
    result[1] = '\0';
    return result;
}

int main()
{
	char *s= solution("hellaao");
	printf("%s\n", s);
	return (0);
}