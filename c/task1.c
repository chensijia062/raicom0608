#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 101
#define MAX_N 10000
typedef struct {
    char str[MAX_STR_LEN];
    int original_index;
} StringNode;
typedef struct {
    char sorted[MAX_STR_LEN];
    int original_index;
} SortedInfo;
typedef struct GroupNode {
    int indices[MAX_N];
    int count;
} GroupNode;
int compare_by_index(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int compare_sorted_info(const void *a, const void *b) {
    SortedInfo *sa = (SortedInfo*)a;
    SortedInfo *sb = (SortedInfo*)b;
    int cmp = strcmp(sa->sorted, sb->sorted);
    if (cmp != 0) return cmp;
    return sa->original_index - sb->original_index;
}
void sort_string(char *str, char *sorted) {
    int len = strlen(str);
    strcpy(sorted, str);
    int count[26] = {0};
    for (int i = 0; i < len; i++) {
        count[sorted[i] - 'a']++;
    }
    int pos = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i] > 0) {
            sorted[pos++] = 'a' + i;
            count[i]--;
        }
    }
    sorted[pos] = '\0';
}

int main() {
    int n;
    scanf("%d", &n);   
    StringNode *strings = (StringNode*)malloc(n * sizeof(StringNode));
    SortedInfo *sorted_infos = (SortedInfo*)malloc(n * sizeof(SortedInfo));
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i].str);
        strings[i].original_index = i;
        sort_string(strings[i].str, sorted_infos[i].sorted);
        sorted_infos[i].original_index = i;
    }
    qsort(sorted_infos, n, sizeof(SortedInfo), compare_sorted_info);
    GroupNode *groups = (GroupNode*)malloc(n * sizeof(GroupNode));
    int group_count = 0; 
    int i = 0;
    while (i < n) {
        groups[group_count].count = 0;
        char *current_sorted = sorted_infos[i].sorted;
        while (i < n && strcmp(sorted_infos[i].sorted, current_sorted) == 0) {
            groups[group_count].indices[groups[group_count].count++] = sorted_infos[i].original_index;
            i++;
        }
        qsort(groups[group_count].indices, groups[group_count].count, sizeof(int), compare_by_index);
        group_count++;
    }
    int *group_first_indices = (int*)malloc(group_count * sizeof(int));
    int *group_order = (int*)malloc(group_count * sizeof(int));
    
    for (int i = 0; i < group_count; i++) {
        group_first_indices[i] = groups[i].indices[0];
        group_order[i] = i;
    }
    for (int i = 0; i < group_count - 1; i++) {
        for (int j = i + 1; j < group_count; j++) {
            if (group_first_indices[group_order[i]] > group_first_indices[group_order[j]]) {
                int temp = group_order[i];
                group_order[i] = group_order[j];
                group_order[j] = temp;
            }
        }
    }
    for (int i = 0; i < group_count; i++) {
        int gid = group_order[i];
        for (int j = 0; j < groups[gid].count; j++) {
            if (j > 0) printf(" ");
            printf("%s", strings[groups[gid].indices[j]].str);
        }
        printf("\n");
    }
    free(strings);
    free(sorted_infos);
    free(groups);
    free(group_first_indices);
    free(group_order);  
    return 0;
}
