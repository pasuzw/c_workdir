#ifndef TEST_H
#define TEST_H

/* enum and structure */
typedef enum E_SELECTION {
    E_COUNT_WORDS,
    E_LONGEST,
    E_LIST_ALL,
    E_SEARCH,
    E_OUTPUT,
    E_DEFAULT
}E_SELECTION;

// typedef enum E_RESULT {
//     E_FALSE,
//     E_TRUE
// }E_RESULT;

typedef struct s_yawl {
    /* data */
    int cnt;
    int max_size;
    int match;
    char target_str[100];
    char longest_str[100];
}t_yawl;



/* Function declare */
extern void init(void);
extern void output(enum E_SELECTION);
// extern E_RESULT compareString(char str1[], char str2[]);
#endif
