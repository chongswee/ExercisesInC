GOH CHONG SWEE
REFLECTION 2 

Self Reflection

	Teamwork:
Throughout the last sprint, there was some improvement of cordination within the group. We work
in pairs, and share a common form of communication (through slack) and have a few skype meetings to 
coordinate work. We have also make better use of the trello board, by adding clearly defined and relevant
tasks that will help us achieve our end goal for the project. All of us also shared a common coding environment 
at LINUX, which we are able to run the same code (with openGL). However, I'm still disappointed in the progress
that the group, even with all the forms of communcation available within the group, I felt that it is still hard to
coorindate without physically meeting.

	Individual learning:
Project:
	OpenGL:
		To help with the project, I went through tutorials on openGL, which are avaialble free on the web(http://www.opengl-tutorial.org/).  Although there are also of basic and helpful information within the tutorial, it is all of them are relevant towards our project. But without going through the full tutorial in sequence, it is not easy to understand the later tutorials without going through the previous parts.(I have minimal knowledge of graphics prior to this course). As such, I felt that we have overestimated our abilities to be able to create objects which move in 3D through coding within a month (just my point of view). With time also spent deciding on our project goal, and creating/understanding the math behind the b-curve. We have little time left to learn how to draw 3D images on code. On the bright side, i really enjoyed the tutorials on openGL and surely it will be useful for me in the future.
		
Physics Engine:
		I did not code much for the full physisc engine yet, but I did manage to make the ball "bounce" with constant gravity. The ball somehow lost energy in the end even though i did not write it to lose any energy. Still figuring out why but it might be some rounding error that cause the number to approach 0 after many iterations(of bounces).
	
Readings:
	I enjoyed the readings for this course a lot, especially TOS (as i've prior knowledge to C). HFC felt more a revision and overview of C. Surely i'll still have to refer to the notes to code in C and for the questions, but generally i'm familiar with C. I enjoyed reading TOS more as learning about "how computers work" is why i took up this course. TOS is really simple to read without too much overly complicated terms or codes which might indimidates me. I did not complete the TOS & HFC exercises early again mainly due to commitments form other courses as I'm taking 5 courses, I'm still trying to adapt to the workload here (compared to Singapore)

Exam Questions 
1.	 What is the average processing speed of a cpu? What is the average transfer rate (read) from memory to cpu? How do we handle the differences?

CPU:				0.5ns
SSD to Memory:	 	25us	50000 x CPU clock 
Memory to CPU:		100ns 	200 x CPU clock
CPU processing speed is much faster than the data transfer rate. In order to resolve this, the CPU is constantly processing information from different processes which reaches 
Cache first to fully utilise the processing time of the CPU. This will allow the CPU to be more efficient and faster processing time overall. 
Also, in order to improve ( by reducing ) the time it takes to reach the CPU, OS and hardware utilize different features such as block transfer, prefetching, buffering and caching 
to minimize the transfter time. (this part of the answer is similar to Q3 OF CH4)

2. 	List down the number of bits each data type occupy. 
	What would you use to store a boolean value and what would you use to store the population in China ?
int 	16
long 	32
short	~8  
float	32
double 	64
char 	8 

Boolean : 	use short, or use bool with boolean library. 
			Alternatively, if many boolean values are required to be stored, we can store it in each bit of a short/long/int, depending of the number of boolean variables.
			i.e. 32 boolean variables can be stored in a long, 16 in int and 8 in short. 
Population in china : long (32 bits - up to 4,294,967,296 )

3. 	What is the benefit of compiling programs separately, then linking at the end ?
	
Compiling programs separately (into separate object code files first) will reduce the time required	to compile by reducing the need to recompile unmodified codes. 
Linking can be done at the end where all the files are compiled and each object file is updated. For a large program, the time saving can be significant. 


HFC: 
	EX 2.5: https://github.com/chongswee/ExercisesInC/blob/master/exercises/ex02.5/find_track_complete_final.c
	EX 3: https://github.com/chongswee/ExercisesInC/blob/master/exercises/ex03/tee_cs.c
	EX 4: I read through the chapter but I had some technical difficulties executing the make file. I will surely upload the 		soltion together with the next reflection.  
TOS:
