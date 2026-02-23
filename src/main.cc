#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../include/shader.h"
#include "../include/glfw_init.h"
#include "../include/gl_init.h"

#define glClearColorVec(v) glClearColor(v.x, v.y, v.z, v.w); 

#include "cube.h"


int
main() {
    GLuint cubeVAO;
    GLuint cubeVBO;
    GLuint lightVAO;

    GLFWwindow* window = glfw::InitGLFWContext(800, 800, "Light Casters", true);
    gl::InitGLContext(glfw::resolution[0], glfw::resolution[1]);
    
    glGenVertexArrays(1, &cubeVAO);
    glBindVertexArray(cubeVAO);

    glGenBuffers(1, &cubeVBO);
    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    /* Shaders */
    gl::glShader cubeShader("./cube.vert", "./cube.frag");
    gl::glShader lightShader("./light.vert", "./light.frag");
    /* End Shaders */

    /* Math */
    glm::vec4 bgColor {glm::vec3(0.2f), 1.0f};

    glm::vec3 cameraPosition {0.0f, 2.0f, -3.0f};
    glm::vec3 cameraUp {0.0f, 1.0f, 0.0f};

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)(glfw::resolution[0])/glfw::resolution[1], 0.3f, 100.0f);
    glm::mat4 view = glm::lookAt(cameraPosition, glm::vec3(0.0f), cameraUp);

    glm::mat4 cubeModel = glm::mat4(1.0f);
    cubeModel = glm::translate(cubeModel, glm::vec3(0.0f));

    glm::mat4 lightModel = glm::mat4(1.0f);
    lightModel = glm::translate(lightModel, glm::vec3(1.0f));
    lightModel = glm::scale(lightModel, glm::vec3(0.5f));
    /* End Math */

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfw::processInput(window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColorVec(bgColor);

        /* Rendering Cube*/
        glBindVertexArray(cubeVAO);
        cubeShader.use();
        cubeShader.setMat4("model", glm::value_ptr(cubeModel));
        cubeShader.setMat4("view", glm::value_ptr(view));
        cubeShader.setMat4("projection", glm::value_ptr(projection));

        glDrawArrays(GL_TRIANGLES, 0, 36);
        cubeShader.use(false);
        /* Rendering Cube*/

        glBindVertexArray(0);

        /* Rendering Light Source */
        glBindVertexArray(lightVAO);
        lightShader.use();
        lightShader.setMat4("model", glm::value_ptr(lightModel));
        lightShader.setMat4("view", glm::value_ptr(view));
        lightShader.setMat4("projection", glm::value_ptr(projection));

        glDrawArrays(GL_TRIANGLES, 0, 36);
        lightShader.use(false);
        /* Rendering Light Source */

        glfwSwapBuffers(window);
    }

    glfwTerminate();
}