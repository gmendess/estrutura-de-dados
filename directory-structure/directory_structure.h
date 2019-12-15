#ifndef _DIRECTORY_STRUCTURE_H
#define _DIRECTORY_STRUCTURE_H

struct directory {
  char* name;
  struct directory* sub_dirs; // diretórios filhos
  struct directory* next; // diretórios irmãos
  struct file* files; // arquivos presentes no diretório
};
typedef struct directory Directory;

struct file {
  char* name;
  size_t size; // tamanho do arquivo
  struct file* next; // arquivos irmãos
};
typedef struct file File;

#endif // _DIRECTORY_STRUCTURE_H