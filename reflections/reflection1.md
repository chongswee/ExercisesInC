Goh Chong Swee
Softsys Reflection 1

Review of Sprint:
	Sprint 1 was my first ever sprint as eduScrum is not taught in Singapore. Overall, I think the sprint was well managed. Initially, we were still figuring out whether to implement a terminal or somethings similar to “bouncing ball”. We managed to agree as a team to pursue the idea of a ball falling down the Brachistochrone curve, which is the curve which will provide the fastest descent between 2 points, a Brachistochrone curve is also a tautochrone curve which means that balls placed at different parts of the curve will reach the bottom at the same time. These interesting properties can be visualized by creating Brachistochrone curve in openGL, and by implementation bullet physics library, we can add forces (gravitational, normal) to the curve and the balls there by illustrating and proving the Brachistochrone curve. All of us worked towards the goal of the project by taking little steps to slowly reach our goal. Ted managed to get the physics engine working, and sketched a slope in blender. We also managed to animate it in blender which gave us a clearer picture of what we can achieve. 
However, I felt that our team was unclear about how to properly utilize Trello to update our project status/tasks and I think we should work on that properly. 

Preparation for sprint review session:
I’m aware that I might be lacking in terms of knowledge when it comes to programming or computing as compared to students who specialize in these fields (I’m an electrical engineer). To prepare for the sprint review, I reading through the necessary chapters of the books, twice, while summarizing each time after I read, which helps me to recall the information I learnt in the books, and drawing out illustrations to help me understand addresses/pointer allocation better. I also searched google for any more in depth explanation of terms, which websites such as stack exchange have very good and clear answers. However, I did an extra chapter on both books as our team was confused on the schedule and unaware that there is a google sheet for the course schedule. On top of that, I also missed out on the questions available in github “exercises in C” and did not prepare according to the questions. Fortunately, I understood the chapters and manage to understand and answer the questions. In future sprint reviews, I’ll attempt all the question within the repo before class as it surely help to strengthen your knowledge and understanding on the topics. 
With regards to the project, all my team mates did their job to research, or draw out the curve, or to draft out the proposal. But since all of us were working alone, I felt that it is not as productive, and felt that we’re working “less as a team” as we’re mainly working on very specific and individual parts. In future tasks, we’ve came to a conclusion to pair up and work on tasks as a pair instead which will should be more efficient in getting work done. 

Exercises in C: 
	I started the exercises a little too late and realized that I’m rushing to complete before the deadline, in these exercise I did realize that it expanded my knowledge by personally writing and compiling/ analyzing the code (especially the portion were we have to debug C code (stack.c) , and analyze in assembly language to find out how optimization work. Although I already have prior knowledge to that, I gave me a better understanding on how things work by running it personally. 
  
  Personal learning goal: 
	   I took up this course to have a better understanding of how computer work, and to be able to develop a software in C by making use     of different tools such as openGL/Physics library. 
  Readings:

  The first few chapters of the ThinkOS did give me a good and simple introduction of computers/compilation/memory works, but I’m looking   forward to more in-depth knowledge on how the whole system works. Headfirst C also allow me to revise and pick up what I might have       forgotten about C, as I learnt C++, and other languages after I learnt C, and wasn’t too clear on some of the concepts and often mix up   C and C++. 


Project: 
  The first sprint did give me a good overview of how graphics work. Without any prior knowledge to graphics is created in program, openGL did taught me many concepts (vertexes, point of view, “drawing with triangles” etc). While working with blender allows me to understand how the physics engine of blender work, which allows user to set different properties for each object such that will collide, bounce, or experience an acceleration. 
Overall:
   I learned a lot from this sprint 1 both from the readings and project. I felt that I should start exercises or finish up task more quickly in the future (instead of waiting for the deadline). 
	  
	  
Headfirst C exercises (CH 1-2):
CH1: https://github.com/chongswee/ExercisesInC/tree/master/exercises/ex01 
CH2: https://github.com/chongswee/ExercisesInC/tree/master/exercises/ex02

ThinkOS questions (CH1-3): 
https://github.com/chongswee/ExercisesInC/blob/master/reading_questions/ch1-3%20hw.docx

Exam Question and Answer:

1.	[HEAD FIRST C] What should you look out for when deallocating memory? >>>
When deallocating memory from a pointer, you should always look out for any other pointer which is pointing to the same address. Accessing an invalid pointer/address will result in segmentation fault.

2.	[HEADFIRST C] How should you increase the size of an array? >>>
	Once the size of the array is set or when malloc is used to allocate a fixed amount of memory, you would need to reallocate it in order to increase its size.
Function void *realloc(void *ptr, size_t new_size );
The function takes in 2 arguments: ptr, and new size, it then either expands the memory allocated for the array (if subsequent memory is free), or deallocate the current memory and assign a new memory of the new size. 
[http://en.cppreference.com/w/c/memory/realloc]

3.	[THINK OS]Can we use hard disk storage for ram memory? What is the benefit of having a larger memory /RAM?>>>
Yes, windows is already using your part of your storage as virtual memory. It is possible to allocate more memory as virtual memory through settings. However, the transfer speed of storage if often much slower than memory, which will result in a slower processing speed. 
Processes run on mainly memory. With larger memory, more processes can be run at once, hence it allows better multitasking. 

4.	[HEAD FIRST C] What is the purpose of a library? When is the library processed during compilation? >>>
Library is often a compilation of functions and features to ease programming. For example, math.h library contains functions which allow calculation of trigo, log, and squareroot. String.h contains function to join, search string etc.. Although it is possible to create a new function which returns a squareroot etc, it is more convenient and often more efficient to use existing libraries for your function. The library functions are processed in the linking stage. 

5. 	[THINKOS] What are the benefits of a compiled language ? >>>
Compiled languages allows program to be compiled and processed into a executable file. The executable file will contain all the required libraries. Optimization options are available during the compilation process, which means that compiled language can perform better at run time (after being compiled properly). 
Interpretted language, on the other hand, can be less efficient as checks are done during run time instead of compile time, while might reduce its performance. Also, libaries have to be properly imported, and interpretter installed when the same file is run on other environments. 
Executable file, does not require user to import library, and can run on most systems without any additional installation of an interpretter. 
