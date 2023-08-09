#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <cmath>
#include <iostream>
#include <vector>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include "shaderProgram.hpp"
#include "HeadingIndicator.hpp"
#include "HIManager.hpp"
#include "texturemanager.hpp"
#include "VertexArrayObject.hpp"


HeadingIndicator* circleFrame;
HeadingIndicator* flight;
HeadingIndicator* triangles;

unsigned int texture1;

float rotationValue = 0.0f;


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
      
        if (key == GLFW_KEY_RIGHT)
        {
            rotationValue += 2.5f;

        }
        else if (key == GLFW_KEY_LEFT)
        {
            rotationValue -= 2.5f;
        }
    }
}


int main(int argc,char** argv)
{
   if(!glfwInit())
      return -1;

   
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
   
   GLFWwindow* window = glfwCreateWindow(800,800,"Heading Indicator",NULL,NULL);
   
   
   if(window==NULL)
   {
      std::cout<<"Pencere Olusturulamadi"<<std::endl;

      glfwTerminate();

      return -1;
   }    

   glfwMakeContextCurrent(window);

   glfwSetKeyCallback(window, key_callback);


   if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
   {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
   }


   // images klasörü altında 2 adet texture mevcut isteğinize göre değiştirebilirsiniz.
   // dilerseniz HIManager.cpp dosyasından uçağın ve üçgen ölçeklerin renginide değiştirebilirsiniz
   texture1 = TextureManager::getInstance()->loadTexture("../images/hi_face_2.jpg");
   
   HIManager* himanager = HIManager::getInstance();
   circleFrame = himanager->createCircle();
   flight = himanager->createFlight();
   triangles = himanager->createScaleTriangles();

   ShaderProgram program;

   program.attachShader("../shaders/vertexshadersource.glsl",GL_VERTEX_SHADER);
   program.attachShader("../shaders/fragmentshadersource.glsl",GL_FRAGMENT_SHADER);
   program.link();

   unsigned int modelMatrixLocation = program.getModelMatrixLocation();
   unsigned int colorLocation = glGetUniformLocation(program.getProgramId(), "color");


   while(!glfwWindowShouldClose(window))
   {
      glClearColor(0.0f, 0.4f, 0.7f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      
      //çizimde kullanılacak olan program nesnesi aktif ediliyor
      program.use();

      // modelMatrix'i tanımlayın ve varsayılan değerle başlatın
      glm::mat4 modelMatrix = glm::mat4(1.0f); 
      // İğnenin dönüşünü burada gerçekleştirin
      modelMatrix = glm::rotate(modelMatrix, glm::radians(rotationValue), glm::vec3(0.0f, 0.0f, 1.0f));
      // Model matrisini OpenGL'ye gönder
      glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));
      glUniform1i(glGetUniformLocation(program.getProgramId(), "useTexture"), true);

      circleFrame->draw();

      glm::mat4 flightModelMatrix = glm::mat4(1.0f);
      glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(flightModelMatrix));
      glUniform3fv(colorLocation, 1, glm::value_ptr(flight->m_Color));
      glUniform1i(glGetUniformLocation(program.getProgramId(), "useTexture"), false);

      flight->drawLine();

      glm::mat4 scaleModelMatrix = glm::mat4(1.0f);
      glUniformMatrix4fv(modelMatrixLocation, 1, GL_FALSE, glm::value_ptr(scaleModelMatrix));
      glUniform3fv(colorLocation, 1, glm::value_ptr(triangles->m_Color));
      glUniform1i(glGetUniformLocation(program.getProgramId(), "useTexture"), false);

      triangles->draw();

      
      glfwSwapBuffers(window);

      glfwPollEvents();
   }

}