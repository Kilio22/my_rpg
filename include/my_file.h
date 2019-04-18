/*
** EPITECH PROJECT, 2018
** fs
** File description:
** fs
*/

#ifndef MY_FS_H_
#define MY_FS_H_

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/*
** O_RDONLY -> LECTURE SEULE
** O_WRONLY -> ECRITURE SEULE
** O_TRUNC -> EFFACE LE CONTENU DU FICHIER LORS DE L'OUVERTURE
** O_APPEND -> ECRIS A LA FIN
** O_CREAT -> SI LE FICHIER N'EXISTE PAS, LE CREE
** O_CREATE -> CREE UN NOUVEAU FICHIER, ECHOUE SI IL EXISTE DEJA
*/

typedef int fd_t;

//stats
int my_file_size(char const *filepath);

//read functions
char *my_file_readall(char const *filepath); //return 0 if err

#endif /* !MY_FS_H_ */
