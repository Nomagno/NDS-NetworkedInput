#define PORT 3210
#define MAXLINE 5

typedef struct {
	_Bool dat[17];
} NI_Data;

unsigned NI_Init(void);
NI_Data NI_FetchInput(void);
