#include<GL/glew.h>
#include <glfw3.h>
#include<iostream>
#include<cmath>
#include<GL/GLU.h>
#include "render_engine.h"
#include <glm.hpp>
#include<gtc/matrix_transform.hpp>
#include<gtc/type_ptr.hpp>
//#include "lighting.h"



using namespace std;

using namespace renderengine;
//using namespace light_engine;



int main(int argc, char** argv) {


	GLFWwindow* window;
	if (!glfwInit())
	{
		return -1;
	}
	cout << "Enter screen width height" << endl;
	unsigned int width,height;
	cin >> width;
	cin >> height;
	window = glfwCreateWindow(width, height, "Render_engine", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}


	glfwMakeContextCurrent(window);
	glViewport(0, 0, width, height);
	if (glewInit() == GLEW_OK)
	{
		cout << "Yeah" << endl;
	}

	cout << "Enter your engine choice: 1 for 2D ,2 for 3D " << endl;
	unsigned int dec;
	cin >> dec;
	
	if (dec == 1)
     {
		cout << "2D Engine" << endl;

		render_engine ren;
		unsigned int vertexsh = ren.vertcompile(ren);
		unsigned int fragsh = ren.fragcompile(ren);
		unsigned int prog = ren.program(ren);




		float vertices[] = {
			0.0f,0.0f,0.0f, 1.0f,0.0f,1.0f,
			0.5f, 0.0f, 0.0f,1.0f,0.0f,0.0f,
			0.0f, 0.5f, 0.0f, 0.0f,0.5f,1.0f,
			 0.0f,  -0.5f, 0.0f,1.0f,1.0f,0.0f,
			 -0.5f,0.0f,0.0f,0.0f,1.0f,1.0f,


			 -1.0f,0.0f,0.0f,1.0f,0.0f,1.0f,
			-0.5f, 0.0f, 0.0f,1.0f,0.0f,0.0f,
			-1.0f, 0.5f, 0.0f, 0.0f,0.5f,1.0f,
			 -1.0f,-0.5f, 0.0f,1.0f,1.0f,0.0f,
			 -1.5f,0.0f,0.0f,0.0f,1.0f,1.0f,

			 1.0f,0.0f,0.0f,1.0f,0.0f,1.0f,
			1.5f, 0.0f, 0.0f,1.0f,0.0f,0.0f,
			1.0f, 0.5f, 0.0f, 0.0f,0.5f,1.0f,
			 1.0f,  -0.5f, 0.0f,1.0f,1.0f,0.0f,
			 0.5f,0.0f,0.0f,0.0f,1.0f,1.0f,

			 0.0f,0.5f,0.0f,1.0f,0.0f,1.0f,
			0.0f, 1.0f, 0.0f,1.0f,0.0f,0.0f,
			0.0f, 1.5f, 0.0f, 0.0f,0.5f,1.0f,
			 -0.5f,  1.0f, 0.0f,1.0f,1.0f,0.0f,
			 0.5f,1.0f,0.0f,0.0f,1.0f,1.0f,

			  0.0f,-0.5f,0.0f,1.0f,0.0f,1.0f,
			0.0f, -1.0f, 0.0f,1.0f,0.0f,0.0f,
			0.0f, -1.5f, 0.0f, 0.0f,0.5f,1.0f,
			 -0.5f, -1.0f, 0.0f,1.0f,1.0f,0.0f,
			 0.5f,-1.0f,0.0f,0.0f,1.0f,1.0f,

			 -1.0f,0.5f,0.0f,1.0f,0.0f,1.0f,
			-1.0f, 1.0f, 0.0f,1.0f,0.0f,0.0f,
			-1.0f, 1.5f, 0.0f, 0.0f,0.5f,1.0f,
			 -1.5f,  1.0f, 0.0f,1.0f,1.0f,0.0f,
			-0.5f,1.0f,0.0f,1.0f,1.0f,0.0f,

			-1.0f,-0.5f,0.0f,1.0f,0.0f,1.0f,
			-1.0f, -1.0f, 0.0f,1.0f,0.0f,0.0f,
			-1.0f, -1.5f, 0.0f, 0.0f,0.5f,1.0f,
			 -1.5f,  -1.0f, 0.0f,1.0f,1.0f,0.0f,
			-0.5f,-1.0f,0.0f,1.0f,1.0f,0.0f,

			1.0f,-0.5f,0.0f,1.0f,0.0f,1.0f,
			1.0f, -1.0f, 0.0f,1.0f,0.0f,0.0f,
			1.0f, -1.5f, 0.0f, 0.0f,0.5f,1.0f,
			 1.5f,  -1.0f, 0.0f,1.0f,1.0f,0.0f,
			0.5f,-1.0f,0.0f,0.0f,1.0f,1.0f,

			1.0f,0.5f,0.0f,1.0f,0.0f,1.0f,
			1.0f, 1.0f, 0.0f,1.0f,0.0f,0.0f,
			1.0f, 1.5f, 0.0f, 0.0f,0.5f,1.0f,
			 1.5f,  1.0f, 0.0f,1.0f,1.0f,0.0f,
			0.5f,1.0f,0.0f,0.0f,1.0f,1.0f,

			0.75f,0.25f,0.0f,1.0f,0.0f,1.0f,
			0.75f, 0.75f, 0.0f,1.0f,0.0f,0.0f,
			0.25f, 0.75f, 0.0f, 0.0f,0.5f,1.0f,
			 0.25f,  0.25f, 0.0f,1.0f,1.0f,0.0f,


		};

		unsigned int indices[] = {
			0,1,2,
			0,1,3,
			0,3,4,
			0,2,4,

			4,5,7,
			4,5,8,
			5,8,9,
			5,7,9,

			1,10,12,
			1,10,13,
			10,11,12,
			10,11,13,

			2,16,19,
			2,16,18,
			16,17,18,
			16,17,19,

			3,21,23,
			3,21,24,
			21,22,23,
			21,22,24,

			7,26,28,
			7,26,29,
			26,27,28,
			26,27,29,


			8,31,34,
			8,31,33,
			31,32,33,
			31,32,34,

			13,36,39,
			13,36,38,
			36,37,38,
			36,37,39,

			12,41,44,
			12,41,43,
			41,42,43,
			41,42,44,

			45,46,47,
			45,48,47


		};

		windowgl gl;


		unsigned int size = sizeof(vertices);
		const void* data;
		data = vertices;
		unsigned int size_index = sizeof(indices);
		const void* data_index;
		data_index = indices;

		buffer buf;
		buf.allocate_buffers(size, data, size_index, data_index);


		gl.initgl();
		// Our own OpenGL initialization
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear the color buffer with current clearing color
			
			
			glUseProgram(prog);
			// render the triangle
			//glTranslatef(0.5f, 0.4f, 0.0f);


			transformation trans;
			trans.transform_engine_rotate(trans);
			//cam.cam_movement(cam,width,height);
			//cam.cam_rotation(cam, width, height);
			glDrawElements(GL_TRIANGLES, size_index, GL_UNSIGNED_INT, 0);

			trans.transform_engine_reset(trans);

			glDrawElements(GL_TRIANGLES, size_index, GL_UNSIGNED_INT, 0);


			glFlush();



			glfwSwapBuffers(window);
			glfwPollEvents();


		}


		glfwTerminate();
	}

	else if (dec == 2)
	{

	cout << "3D Engine" << endl;
	
	render_engine ren;
	unsigned int vertexsh = ren.vert3dcompile(ren);
	unsigned int fragsh = ren.fragcompile(ren);
	unsigned int prog = ren.program3d(ren);
	

	//lightshader light;
	//unsigned int vert_compile_light = light.vert_compile_light(light);
	//unsigned int frag_compile_light = light.frag_compile_light(light);
	//unsigned int prog_light = light.program_light(light);

	//unsigned int vert_compile_norm = light.v_shader(light);
	//unsigned int frag_compile_norm = light.f_shader(light);
	//unsigned int prog_norm = light.program_light_norm(light);




	depth d;
	d.depthtest();


	float vertices[] = {
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f, 
		 0.5f,  0.5f, -0.5f, 
		 0.5f,  0.5f, -0.5f, 
		-0.5f,  0.5f, -0.5f, 
		-0.5f, -0.5f, -0.5f, 

		-0.5f, -0.5f,  0.5f, 
		 0.5f, -0.5f,  0.5f, 
		 0.5f,  0.5f,  0.5f, 
		 0.5f,  0.5f,  0.5f, 
		-0.5f,  0.5f,  0.5f, 
		-0.5f, -0.5f,  0.5f, 

		-0.5f,  0.5f,  0.5f, 
		-0.5f,  0.5f, -0.5f, 
		-0.5f, -0.5f, -0.5f, 
		-0.5f, -0.5f, -0.5f, 
		-0.5f, -0.5f,  0.5f, 
		-0.5f,  0.5f,  0.5f, 

		 0.5f,  0.5f,  0.5f, 
		 0.5f,  0.5f, -0.5f, 
		 0.5f, -0.5f, -0.5f, 
		 0.5f, -0.5f, -0.5f, 
		 0.5f, -0.5f,  0.5f, 
		 0.5f,  0.5f,  0.5f, 

		-0.5f, -0.5f, -0.5f, 
		 0.5f, -0.5f, -0.5f, 
		 0.5f, -0.5f,  0.5f, 
		 0.5f, -0.5f,  0.5f, 
		-0.5f, -0.5f,  0.5f, 
		-0.5f, -0.5f, -0.5f, 

		-0.5f,  0.5f, -0.5f, 
		 0.5f,  0.5f, -0.5f, 
		 0.5f,  0.5f,  0.5f, 
		 0.5f,  0.5f,  0.5f, 
		-0.5f,  0.5f,  0.5f, 
		-0.5f,  0.5f, -0.5f 

	};


	windowgl gl;


	unsigned int size = sizeof(vertices);
	const void* data;
	data = vertices;
	//unsigned int size_index = sizeof(indices);
	//const void* data_index;
	//data_index = indices;
	
	//aloc_buffer buf;
	//buf.allocate_buffer_light(size, data);


	gl.initgl();
	// Our own OpenGL initialization
	while (!glfwWindowShouldClose(window))
	{
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Clear the color buffer with current clearing color
		camera cam;
		cam.delta_cam(cam,width,height);
		input input;
		input.input_view(window,width,height);

		//glUseProgram(prog_light);
		 
		//tranform_light trans;
		//trans.transformation_light(trans,width,height);


		// render the triangle
		//glTranslatef(0.5f, 0.4f, 0.0f);


		transformation trans;
		trans.transform_3d_engine(trans,width,height);
	trans.transform_engine_scale(trans);
		trans.transform_engine_rotate(trans);
		cam.cam_movement(cam, width, height);
	cam.cam_rotation(cam, width, height);
	

		glDrawArrays(GL_TRIANGLES, 0, 36);
		trans.transform_engine_reset(trans);
		trans.transform_engine_translate(trans);
		
		//glUseProgram(prog_norm);
		//trans.transformation_light_norm(trans,width,height);
		
		glDrawArrays(GL_TRIANGLES, 0, 36);
		//glDrawElements(GL_TRIANGLES, size_index, GL_UNSIGNED_INT, 0);


		glFlush();



		glfwSwapBuffers(window);
		glfwPollEvents();


	}


	glfwTerminate();


 }

	return 0;
}
