// Question1/Student.c
// ------------------------------------------------------------
// CS Lab - Valid Parentheses (STACK PRACTICE)
//
// Task:
// Implement `isValid(const char *s)`.
// Given a string s containing only: () {} []
// return true if it is a valid parentheses string, else false.
//
// Valid rules:
// 1) Open brackets must be closed by the same type of brackets.
// 2) Open brackets must be closed in the correct order.
// 3) Every close bracket has a corresponding open bracket.
//
// Examples:
//   s = "()"        -> true
//   s = "()[]{}"    -> true
//   s = "(]"        -> false
//   s = "([)]"      -> false
//   s = "{[]}"      -> true
//   s = ""          -> true   (empty string is valid)
//
// How to run tests (from the folder containing the Makefile):
//   make run1
// ------------------------------------------------------------

#include "Student.h"
#include <stdbool.h>
#include <stddef.h>  // size_t
#include <string.h>  // strlen

bool isValid(const char *s) {
    // TODO: Implement using a stack.
    //
    // Recommended approach:
    // - Use a char array as a stack to store opening brackets.
    // - Scan the string from left to right:
    //   - If you see an opening bracket, push it.
    //   - If you see a closing bracket:
    //       * stack must not be empty
    //       * top of stack must match the closing bracket type
    //       * then pop
    // - At the end, stack must be empty.
    //
    // Helpful matching pairs:
    //   ')' matches '('
    //   ']' matches '['
    //   '}' matches '{'
    //
    // Corner cases:
    // - s == NULL -> return false
    // - odd length strings can’t be valid 
    //
    // Note:
    // - Input contains only bracket characters, per the prompt.

if(s[0] == '\0'){  //quick check if string is empty, that is valid
    return true;
}

    size_t s_length = strlen(s); //get size of s
    size_t odd_comp = 2;
    size_t zero = 0;

if (s_length % odd_comp != zero) { //if odd, invalid
        return false;
}

    typedef struct {   // intiate array stack, wrap in a struct is cleaner.
        char stack[s_length]; //stack will be as big as the array.
        int top;
    } Stack;

    Stack stringstack1;
    Stack *stringstackptr;

    stringstackptr = &stringstack1;
    stringstackptr->top = -1;    //defined NULL, top of stack.

    for (size_t i = 0; i < s_length; i++) { //iterate through the string
        char c_element = s[i];

        if ((c_element == '(') || (c_element == '{') || (c_element == '[')) { //if open bracket
            //push to stack
           stringstackptr->top++; //increment top
           stringstackptr->stack[stringstackptr->top] = c_element; //insert element
        }

         switch(c_element){

            case ')': //check if closed bracket
            if(stringstackptr->top != -1){ //if stack is NOT empty
               if(stringstackptr->stack[stringstackptr->top] == '('){ //if matching, then we pop
                 stringstackptr->top--; //decrement top 
               }
            }
                break;

            case '}':
             if(stringstackptr->top != -1){ //if stack is NOT empty
               if(stringstackptr->stack[stringstackptr->top] == '{'){ //if matching, then we pop
                 stringstackptr->top--; //decrement top 
               }
            }
               break;

            case ']':
             if(stringstackptr->top != -1){ //if stack is NOT empty
               if(stringstackptr->stack[stringstackptr->top] == '['){ //if matching, then we pop
                 stringstackptr->top--; //decrement top 
               }
            }   
                break;
            default:
                continue; //invalid
        }
        }

        if(stringstackptr->top == -1){ // if stack is empty for loop.
    return true; //valid string
} else {
    return false; //invalid string
}
    }

