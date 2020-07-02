#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

template <typename T>
struct Node
{
    T val;
    Node* next;
};
Node<int>* Rooth = NULL;
Node<int>* END   = NULL; // helper pointer
Node<int>* aux   = NULL;
//Basics


void add_node(int val){
    if(Rooth != NULL) 
    {
        END->next = new Node<int>();//Create empty node pointing next to END
        END->next->val = val;  
        aux = END;
        END = END->next;//update to last position
        END->next  = Rooth; //last position points to Rooth
    }
    // if the node is empty and it hasn't been created AMIGOS VOY AL BAÑO :D
    else // only one time
    {   
        Rooth = new Node<int>(); ///4
        Rooth->val = val;
        END = Rooth;
    }
}

//REMOVE
void remove_node(void){
    //aux apunta a ruth :B
     aux -> next = Rooth;
    //delte END //free memory
    delete END;
    //Mover END a aux
    END = aux;
    //mover aux a travez de todos los valores y parar hasta que el siguiente sea END
    while(aux->next != END ){///??
        aux = aux->next;
    }
}

//Recorrer
//--> avanzar
//Node a;
//crear nodos y ya
//move_next(&a);
//Node*n  = &a;
//n es independiete de a;
//movemos n
// n se destruye
//a quede intacto
void move_next(Node<int>*& n){
    n = n->next;
}
/* _________
  |         |
  |  Z Z Z  |
  |__  _____|
     |/
   |\      _,,,--,,_
   /,`.-'`'   ._  \-;;,
  |,4-  ) )_   .;.(  `'-'
 '---''(_/._)-'(_\_)
*/
//int b = 3;
// increment(b);
//  a sea un espejo de b 
// si cambio a cambio b 
// b se incremento; 
//a = *b
//a++
// int b = 3;
// int& a = b; es lo mismo que int*a = &b;
// int* p ;
//incremnt(p);
void increment(int* a)
{
    a++;
}

// una funcion que nos diga la lista es cirular o no.
// Nada mas tenes tienes un Head
/*
           __________
          | ¿CICLICA |
          |   O NO?  |
          |___  _____|
     /\___/\  |/
    / 0 . 0 \
    \   ^   /   _____
    /       \  / ____|
   /         \/ /
  |  | | | |  | |
 (__(,,)_(,,)__)
*/
//ROOT
// A->B->C->D // finit linked
// A->B->C->D->A // circular
// map<Node*> checkpoint
// checkpoint[head]; // add checkpoint in the map
// fill each checkpoint and check if not repeated
// 
void TestCiclity(Node<int>* head)
{
    Node<int>* slow, *fast;
    *slow = *head;
    *fast = *head;
    move_next(slow);
    fast = fast->next->next;
 
    //                   sf         
    //1 -> 2 -> 3 -> 4 -> 5 -> 6 ->1 ->2 ->3
 
    while (1)
    {
        if(slow == NULL | fast == NULL)
        {
            printf("Finite sigle linked list");
            break;
        }
        else if(&fast == &head | &fast == &slow)
        {
            printf("Circular linked list");
            break;
        }
        move_next(slow);
        fast = fast->next->next;
    }

}
/*
        _
        \ `*-.
         )  _ `-.
        .   :  `. .
        : _     '  \
        ; o ` _.    `*-._ 
        `-.- '            `-.
          ;         `         `.
          :.         .          \
          . \  .     :    . - '  .
          '  `+. ;   ;   '       :
          :  '   |      ;        ;--.
          ; '    :  :`-:      __.`*  ;
         /  .*'  ;  .*`- +'    `*'
        *-*  `*--*    `*--*'
*/
void print_list(Node<int>* head){ // ANIMO GIS! :D MUY GRANDE GIS!
    Node<int>* temp = head; 
    printf("List\r\n");
    do
    {
        printf("Lista calixta: %i\r\n", temp->val);
        move_next(temp);
        //temp = temp->next;
    } while(head != temp);
}

int main(int argc, char const *argv[])
{
   
    vector<int> ints {2,3,6,1,3,40};
    for_each(ints.begin(), ints.end(), [](int i){add_node(i);});
    Node<int>* n1 = Rooth;//:3
    print_list(n1);

    return 0;
}


//juay de rito? :()
/*
         __________________
        |                  |
        |     TONAYAN      |
        |_____  ___________|
      (\__/)  |/
   ⠀  (•ㅅ•)      
　＿ノ ヽ ノ＼  __    
 /　`/ ⌒Ｙ⌒ Ｙ　ヽ     
( 　(三ヽ人　 /　　 |     
|　ﾉ⌒＼ ￣￣ヽ　 ノ    
ヽ＿＿＿＞､＿＿_／ 
　　 ｜( 王 ﾉ〈    
　　 /ﾐ`ー―彡\

⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣠⣶⡾⠏⠉⠙⠳⢦⡀⠀⠀⠀⢠⠞⠉⠙⠲⡀⠀
⠀⠀⠀⣴⠿⠏⠀⠀⠀⠀⠀⠀⢳⡀⠀ ⡏ ⠀⠀⠀⠀⠀⢷
⠀⠀⢠⣟⣋⡀⢀⣀⣀⡀⠀⣀⡀⣧⠀⢸⠀⠀⠀⠀⠀  ⡇
⠀⠀⢸⣯⡭⠁⠸⣛⣟⠆⡴⣻⡲⣿⠀⣸⠀⠀OK⠀  ⡇
⠀⠀⣟⣿⡭⠀⠀⠀⠀⠀⢱⠀⠀⣿⠀ ⢹⠀⠀⠀⠀⠀ ⡇
⠀⠀⠙⢿⣯⠄⠀⠀⠀⢀⡀⠀⠀⡿⠀⠀⡇⠀⠀⠀⠀ ⡼
⠀⠀⠀⠀⠹⣶⠆⠀⠀⠀⠀⠀⡴⠃⠀⠀⠘⠤⣄⣠⠞⠀
⠀⠀⠀⠀⠀⢸⣷⡦⢤⡤⢤⣞⣁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⣤⣴⣿⣏⠁⠀⠀⠸⣏⢯⣷⣖⣦⡀⠀⠀⠀⠀⠀⠀
⢀⣾⣽⣿⣿⣿⣿⠛⢲⣶⣾⢉⡷⣿⣿⠵⣿⠀⠀⠀⠀⠀⠀
⣼⣿⠍⠉⣿⡭⠉⠙⢺⣇⣼⡏⠀⠀⠀⣄⢸⠀⠀⠀⠀⠀⠀
⣿⣿⣧⣀⣿.........⣀⣰⣏⣘⣆⣀⠀⠀

   +--------------+
   |.------------.|
   ||            ||
   ||   O w 0    ||
   ||            ||
   ||            ||
   |+------------+|
   +-..--------..-+
   .--------------.
  / /============\ \
 / /==============\ \
/____________________\
\____________________/

(:v I'm sorry) xD

              _
             | |
             | |===( )   //////
             |_|   |||  | o o|
                    ||| ( c  )                  ____
                     ||| \= /                  ||   \_
                      ||||||                   ||     |
                      ||||||                ...||__/|-"
                      ||||||             __|________|__
                        |||             |______________|
                        |||             || ||      || ||
                        |||             || ||      || ||
------------------------|||-------------||-||------||-||-------
                        |__>            || ||      || ||
*/