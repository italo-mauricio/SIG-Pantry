typedef struct user User;
struct user {
    char nameUser[101];
    char emailUser[40];
    int day;
    int month;
    int year;
    char usernameUser[20];
    char senhaUsuario[20];
    char status;
    char userDate[20]; 
};

void userRegistrationModule(void);
char userMenuScreen(void);
int updateUser(void);
void escolhafuncao(char);
void userInfo(void);
int saveUser(User*);
int listUserInfo(void);
void displayUserInfo(User* user);
int searchUserInfo(void);
int deleteUserInfo(void);
int validateUser(char* user);
char updateMenu(void);
