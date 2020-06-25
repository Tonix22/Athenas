#include <iostream>


//val -> 
//val <-

struct Node
{
    int val;
    Node* next;
};
Node* Rooth = NULL;
Node* END   = NULL; // helper pointer
Node* aux   = NULL;
//Basics

//ADD

//add_node(4);
//add_node(3);
//add_node(5);
//4->3->5
//4->5
//       E(5)-->
//R(4)-->N(5)-->

void add_node(int val){
    if(Rooth != NULL) 
    {
        END->next = new Node();//Create empty node pointing next to END
        END->next->val = val;  
        aux = END;
        END = END->next;//update to last position
        END->next  = Rooth; //last position points to Rooth
    }
    // if the node is empty and it hasn't been created AMIGOS VOY AL BAÑO :D
    else // only one time
    {   
        Rooth = new Node(); ///4
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
void move_next(Node* n){
    n = n->next;
}
//Advanced
//FIND
//SORT





int main(int argc, char const *argv[])
{
    
    /* code */
    return 0;
}
//juay de rito? :()
/*
      (\__/) 
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
⠀⠀⢠⣟⣋⡀⢀⣀⣀⡀⠀⣀⡀⣧⠀⢸⠀⠀⠀⠀⠀   ⡇
⠀⠀⢸⣯⡭⠁⠸⣛⣟⠆⡴⣻⡲⣿⠀⣸⠀⠀OK⠀   ⡇
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
   ||    O w 0   ||
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