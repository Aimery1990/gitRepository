
#include<iostream>

using namespace std;

typedef unsigned int uint;
typedef int fd_t;
typedef uint len_t;

class FBK_T{
    enum{
        SUCCESS = 0,
        GEN_ERROR = 1,
        TIMEOUT_ERROR = 2,
    };
};

class IPV_T{
    enum{
        IPV4,
        IPV6
    };
};

class BLOCK_T{
    enum{
        BLOCK,
        NONE_BLOCK
    };
};

class TCP_SER{

public:
    virtual fd_t new_server(string ip, uint port, IPV_T ipv, BLOCK_T blk ) = 0;
    virtual FBK_T broadcaster( const char * msg, uint len ) = 0;
    virtual FBK_T broadcaster_except( const char * msg,  uint len, int * sockfds, uint sfd_num ) = 0;
    virtual FBK_T group_sender( const char * msg,  uint len, int * sockfds, uint sfd_num ) = 0;
    virtual FBK_T group_receiver( char ** msgs, uint * lens, int * sockfds, uint sfd_num ) = 0;
    virtual FBK_T short_sender( const char * msg, uint len, int sockfd, len_t * snt_len, uint timeout = 0 ) = 0;
    virtual FBK_T short_receiver( char * msg, uint * len, int sockfd, len_t * rcv_len, uint timeout = 0 ) = 0;
    virtual FBK_T long_sender( const char * msg, uint len, int sockfd, len_t * snt_len, uint timeout = 0 ) = 0;
    virtual FBK_T long_receiver( char * msg, uint * len, int sockfd,  len_t * rcv_len, uint timeout = 0 ) = 0;
    virtual FBK_T delete_server(int sockfd) = 0;
private:
    fd_t srv_fd;
    uint univrs_timeout;

};


int main()
{

    return 0;
}