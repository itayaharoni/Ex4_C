#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frequency.h"
#define NUM_LETTERS 26

node* new_node(){
    node* new_n=(node*)malloc(sizeof(node));
    if(new_n==NULL)
    return NULL;
    new_n->count=0;
    new_n->flag=FALSE;
    for (size_t i = 0; i < 26; i++)
    {
        new_n->children[i]=NULL;
    }
    new_n->letter=0;
    new_n->word=NULL;
    return new_n;
}
node* add_to_trie(char c,node* p){
    if(p->children[c-'a']==NULL){
        node* child=new_node();
        p->children[c-'a']=child;
        child->letter=c;
        if(p->word==NULL){
        child->word=(char*)calloc(2,sizeof(char));
        if (child->word==NULL)
        {
            return NULL;
        }
        child->word[0]=c;
        }else{
            int w_len;
            w_len=strlen(p->word);
            child->word=(char*)calloc(w_len+2,sizeof(char));
        if (child->word==NULL)
        {
            return NULL;
        }
        size_t j=0;
            for (j = 0; j < w_len; j++)
            {
                child->word[j]=p->word[j];
            }
            child->word[j]=c;
        }
    }
        return p->children[c-'a'];
}
char scale_down(char c){
    return (c+32);
}
char is_letter(char c){
    if(c>='a'&&c<='z') return c;
    return 0;
}
int is_capital(char c){
    if(c>='A'&&c<='Z') return 1;
    return 0;
}
void build_trie(node* root){
    char c=0;
    int n=0;
    node* p=root;
    while(n!=EOF){
        while(c!='\n' && c!='\r' && c!='\t' && c!=' ' && n!=EOF){
            if(is_capital(c))
            c=scale_down(c);
            if(is_letter(c))
            p=add_to_trie(c,p);
            if(p==NULL){
                return;
            }
            n=scanf("%c",&c);
        }
        if(p->flag==FALSE){
            p->flag=TRUE;
            p->count++;
        }else{
            p->count++;
        }
        while((c=='\n' || c=='\r' || c=='\t' || c==' ')&& n!=EOF){
            n=scanf("%c",&c);
        }
        p=root;
    }
}
void print_up_order(node* root){
    if (root==NULL)
    {
        return;
    }
    if(root->flag==TRUE){
        printf("%s %ld\n",root->word,root->count);
    }
    for (int i = 0; i < 26; i++)
    {
        print_up_order(root->children[i]);
    }
    
}
void print_down_order(node* root){
    if (root==NULL)
    {
        return;
    }
    for (int i = 25; i >=0; i--)
    {
        print_down_order(root->children[i]);
    }
        if(root->flag==TRUE){
        printf("%s %ld\n",root->word,root->count);
    }
    
}
void free_node(node* n){
    free(n->word);
    free(n);
}
void free_trie(node* root){
    if (root==NULL)
    {
        return;
    }
    
    for (size_t i = 0; i < 26; i++)
    {
        free_trie(root->children[i]);
    }
    free_node(root);
}

int main(int argc,char* argv[]){
    node* root=new_node();
    if (root==NULL)
    {
        exit(1);
    }
    build_trie(root);
    if (argc>1)
    {
        if (*argv[1]=='r')
        {
            print_down_order(root);
        }else{
            print_up_order(root);
        }
    }else{
        print_up_order(root);
    }
    free_trie(root);
    return 0;
}