//
//  main.cpp
//  FamilyTree
//
//  Created by DoganCan on 12/19/12.
//  Copyright (c) 2012 Dogan Can Dogan. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Struct spouse

struct Spouse{
    
    string name;
    int dateOfBirth;
    
};

// Struct individual

struct Individual{
    
    string name, gender;
    int dateOfBirth, nodeID, parentID, childCount;
    Individual** children;
    Spouse* spouse;
    
};

// Individual array of family and its counter

Individual** familyTree ;
int individualCounter = 0;

// Print parent function

void printParent(string individualName){
    
    bool found = false;
    
    for (int i = 0; i < individualCounter; i++ ){
        
        for(int k = 0; k < familyTree[i]->childCount; k++ )
            
            if(familyTree[i]->children[k]->name == individualName){
                
                cout<< individualName << "'s parent is "<< familyTree[i]->name << " and " << familyTree[i]->spouse->name<<endl ;
            
                found = true ;
            }
    }
    
    if(!found)
        cout<< "Parent is not found !!!" << endl;
        
    
}


void printGrandparents(string individualName){
    
    bool found = false;
    
    cout << individualName <<"'s grandparents are ";

    
    for (int i = 0; i < individualCounter; i++ ){
        
        for(int k = 0; k < familyTree[i]->childCount; k++ )
            
            for(int j = 0; j < familyTree[i]->children[k]->childCount; j++ )

                if(familyTree[i]->children[k]->children[j]->name == individualName){
                    
                    cout<< familyTree[i]->name << " and " << familyTree[i]->spouse->name<<endl ;
                    
                    found = true ;

                }
            
            
            }
    
    if(!found)
        cout<< "not found !!!" << endl;


}


void printChildren(string individualName){
    
    bool found = false;
    
    for (int i = 0; i < individualCounter; i++ ){
        
        if (familyTree[i]->name == individualName){
            
            if(familyTree[i]->childCount){
                
                found = true;
                
                cout << individualName <<"'s children: ";
                
                for(int k = 0; k < familyTree[i]->childCount; k++ )
                    
                    cout<< familyTree[i]->children[k]->name<< ", ";
            }
                }
        }
   
    if(!found)
        cout<< "Parent is not found !!!" << endl;

}

void printGrandchildren(string individualName){


    bool found = false;
    
    cout << individualName <<"'s grandchildren are ";

    for (int i = 0; i < individualCounter; i++ ){
        
        if (familyTree[i]->name == individualName){
            
            if(familyTree[i]->childCount)
                
                for(int k = 0; k < familyTree[i]->childCount; k++ )
                    
                    if(familyTree[i]->children[k]->childCount){
                        
                        found = true;
                        
                        for(int j = 0; j < familyTree[i]->children[k]->childCount; j++ )
                            
                            cout<< familyTree[i]->children[k]->children[j]->name<< ", ";
                    }
            }}

    if(!found)
        cout<< "not found !!!" << endl;
}


void printSiblings(string individualName){
    
    bool found = false;
    
    cout << individualName <<"'s siblings ";

    
    for (int i = 0; i < individualCounter; i++ ){
        
        for(int k = 0; k < familyTree[i]->childCount; k++ )
            
            if(familyTree[i]->children[k]->name == individualName){
                
                if(familyTree[i]->childCount > 1){
                    
                    found = true ;

                    for(int j = 0; j < familyTree[i]->childCount; j++ ){
                    
                        if(familyTree[i]->children[j]->name != individualName)
    
                            cout<< familyTree[i]->children[j]->name<<", ";
                }
                }
            }
            }

    if(!found)
        cout<< "not found !!!" << endl;

}

bool isSibling(string individualName1, string individualName2){
    
    
    bool found = false;
    
    for (int i = 0; i < individualCounter; i++ )
        
        for(int k = 0; k < familyTree[i]->childCount; k++ )
            
            if(familyTree[i]->children[k]->name == individualName1)
                
                for(int l = 0; l < familyTree[i]->childCount; l++ )

                    if(familyTree[i]->children[l]->name == individualName2)
                        
                        found = true;
            
  /*
    if(!found)
        cout<< "They are not siblings !!!" << endl;
            
    else
        cout<< "They are siblings."<<endl;
    */
    return found ;

}


void printCousins(string individualName){

    bool found = false;
    
    cout << individualName <<"'s cousins are ";
    
    
    for (int i = 0; i < individualCounter; i++ )
        
        for(int k = 0; k < familyTree[i]->childCount; k++ )
            
            for(int j = 0; j < familyTree[i]->children[k]->childCount; j++ )
                
                if(familyTree[i]->children[k]->children[j]->name == individualName){
                    
                    for(int l = 0; l < familyTree[i]->childCount; l++ )
                        
                        for(int m = 0; m < familyTree[i]->children[l]->childCount; m++ )

                            if(familyTree[i]->children[l]->children[m]->name != individualName && !isSibling(familyTree[i]->children[l]->children[m]->name, individualName)){
                                
                                cout << familyTree[i]->children[l]->children[m]->name << ", ";
                                found = true ;
                        
                            }
                
            }

    if(!found)
        cout<< "not found !!!" << endl;

}


bool getCousins(string individualName){
    
    bool found = false;
    
    for (int i = 0; i < individualCounter; i++ )
        
        for(int k = 0; k < familyTree[i]->childCount; k++ )
            
            for(int j = 0; j < familyTree[i]->children[k]->childCount; j++ )
                
                if(familyTree[i]->children[k]->children[j]->name == individualName){
                    
                    found = true ;
                    
                    for(int l = 0; l < familyTree[i]->childCount; l++ )
                        
                        for(int m = 0; m < familyTree[i]->children[l]->childCount; m++ )
                            
                            if(familyTree[i]->children[l]->children[m]->name != individualName)
                                
                                cout << familyTree[i]->children[l]->children[m]->name << ", ";
                    
                }
    
    return found ;
    
}



bool getSiblings(string individualName){
    
    bool found = false;
    
    for (int i = 0; i < individualCounter; i++ ){
        
        for(int k = 0; k < familyTree[i]->childCount; k++ )
            
            if(familyTree[i]->children[k]->name == individualName){
                
                if(familyTree[i]->childCount > 1){
                    
                    found = true ;
                    
                    for(int j = 0; j < familyTree[i]->childCount; j++ ){
                        
                        if(familyTree[i]->children[j]->name != individualName)
                            
                            cout<< familyTree[i]->children[j]->name<<", ";
                    }
                }
            }
    }
    
    return found;
    
}

//print whole family layer by layer

void printWholeFamily( Individual *root){
    
    while(root->childCount || getSiblings(root->name) || getCousins(root->name)){
          
        cout<< root->name << ", " ;
        if(getCousins(root->name));
        else(getSiblings(root->name));
        
        if (!root->children[0]->childCount){
            break;
        }
        
        else
            root = root->children[0];

        cout<< endl;
    }

      

}





int main(int argc, const char * argv[])
{
    
    
    // Since we are creating the tree with individuals, not counting spouses
    // We need to know number of individuals for an efficient program
    
    // Number of individuals in family tree
    string countLines;
    
    // Don't forget to change directory before compiling
    
    ifstream infile("/Users/DoganCan/Desktop/family.txt");
    
    while (infile>>countLines) {
        if(countLines == "spouse")
            break;
        else
            individualCounter++;
    }
    
    // the loop reads string by string, since each individual has 5 string
    // I have to divide it by 5 to get number of ind.
    individualCounter = individualCounter/5 ;
    
    //cout<< individualCounter <<endl   ;
    
    
    // Set file pointer to the beginning, in order to create the tree
    infile.seekg(0);
    
    
    familyTree = new Individual *[individualCounter];
    
    
    for(int i = 0; i < individualCounter; i++ ){
        
        familyTree[i] = new Individual ;
        
        familyTree[i]->childCount = 0;
        familyTree[i]->children = new Individual* [5];

        
        // read inputs from the file
        
        infile>> familyTree[i]->name>> familyTree[i]->dateOfBirth>> familyTree[i]->gender >> familyTree[i]->nodeID>>familyTree[i]->parentID ;
        
            
        // lookForAncestors
        // compare individuals parentID with previous individuals nodeID
        
        for (int k = 0; k < i ; k++){
            
            if(familyTree[k]->nodeID == familyTree[i]->parentID){
                
                familyTree[k]->children[familyTree[k]->childCount] = familyTree[i]  ;
                                
                familyTree[k]->childCount++;
        }
        
        }
    }
    
        
    // Uncomment to check parent-children relationship 
    
    /*
    
    for(int i = 0; i < individualCounter; i++ ){
        
        //cout<<familyTree[i]->name << familyTree[i]->childCount << endl ;
        
        for(int k = 0; k < familyTree[i]->childCount ; k++)
        
            cout<<  familyTree[i]->name <<"---->"<< familyTree[i]->children[k]->name <<","<<"\t\t";
      
        cout<< endl;
        
    }
    
    */
    
    string spouse, spouseName;
    int spouseNodeID, spouseDOB;
    
    while (infile>> spouse >> spouseName >>spouseNodeID >> spouseDOB) {
        
        Spouse *newSpouse = new Spouse ;
        
        newSpouse->name = spouseName ;
        newSpouse->dateOfBirth = spouseDOB ;
        
        for (int i = 0; i< individualCounter ; i++){
            
            if(spouseNodeID == familyTree[i]->nodeID){
                familyTree[i]->spouse = newSpouse ;
                
                // Uncomment to check spouse relationship
                //cout<< familyTree[i]->spouse->name << " is spouse of " << familyTree[i]->name << endl;
            }
        }
        
    }
    
    // Uncomment to check functions

     
  //  printParent("Meral");
    //printChildren("Cem");
    //printGrandchildren("Meral");
    //printGrandparents("Meral");
    //printSiblings("Cem");
    //printCousins("Emre");
    //isSibling("Ceyda", "Ahmet");
    printWholeFamily(familyTree[0]);
    return 0;
}




