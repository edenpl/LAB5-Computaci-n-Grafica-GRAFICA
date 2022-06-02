#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <random>
#include <vector>


void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

const unsigned int SCR_WIDTH = 1200;
const unsigned int SCR_HEIGHT = 1200;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 aColor;\n"
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"   ourColor = aColor;\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0f);\n"
"}\n\0";

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {


                //cola
         -0.95f,-0.1f, 0.0f,  1.0f, 0.5f, 0.0f,
         -0.82f,-0.09f, 0.0f,  1.0f, 0.5f, 0.0f,
         -0.77f,0.01f, 0.0f,  1.0f, 0.5f, 0.0f,

         -0.95f,-0.1f, 0.0f,  1.0f, 1.0f, 0.0f,
         -0.82f,-0.09f, 0.0f,   1.0f, 1.0f, 0.0f,
         -0.8f,-0.14f, 0.0f,  1.0f, 1.0f, 0.0f,

         -0.8f,-0.14f, 0.0f,  1.0f, 0.5f, 0.0f,
         -0.82f,-0.09f, 0.0f, 1.0f, 0.5f, 0.0f,
         -0.68f,-0.08f, 0.0f, 1.0f, 0.5f, 0.0f,

         -0.82f,-0.09f, 0.0f,  1.0f, 1.0f, 0.0f,
         -0.75f,0.05f, 0.0f,    1.0f, 1.0f, 0.0f,
         -0.62f,0.05f, 0.0f,   1.0f, 1.0f, 0.0f,

         -0.82f,-0.09f, 0.0f,  1.0f, 0.5f, 0.0f,
         -0.62f,0.05f, 0.0f,  1.0f, 0.5f, 0.0f,
         -0.58f,-0.08f, 0.0f,  1.0f, 0.5f, 0.0f,

         -0.62f,0.05f, 0.0f, 1.0f, 0.5f, 0.0f,
         -0.58f,-0.08f, 0.0f, 1.0f, 0.5f, 0.0f,
         -0.5f,0.0f, 0.0f, 1.0f, 0.5f, 0.0f,

         -0.62f,0.05f, 0.0f, 1.0f, 0.5f, 0.0f,
         -0.49f,0.09f, 0.0f, 1.0f, 0.5f, 0.0f,
         -0.46f,-0.02f, 0.0f, 1.0f, 0.5f, 0.0f,

         -0.62f,0.05f, 0.0f,  1.0f, 1.0f, 0.0f,
         -0.58f,0.13f, 0.0f,   1.0f, 1.0f, 0.0f,
         -0.49f,0.09f, 0.0f,  1.0f, 1.0f, 0.0f,

         -0.58f,0.13f, 0.0f,  1.0f, 1.0f, 0.0f,
         -0.49f,0.09f, 0.0f,   1.0f, 1.0f, 0.0f,
         -0.46f,0.16f, 0.0f,  1.0f, 1.0f, 0.0f,

         -0.49f,0.09f, 0.0f, 1.0f, 0.5f, 0.0f,
         -0.46f,-0.02f, 0.0f, 1.0f, 0.5f, 0.0f,
         -0.41f,0.08f, 0.0f, 1.0f, 0.5f, 0.0f,

         -0.49f,0.09f, 0.0f,  1.0f, 1.0f, 0.0f,
         -0.43f,0.22f, 0.0f,  1.0f, 1.0f, 0.0f,
         -0.35f,0.18f, 0.0f,  1.0f, 1.0f, 0.0f,

         -0.49f,0.09f, 0.0f,  1.0f, 0.5f, 0.0f,
         -0.35f,0.18f, 0.0f,  1.0f, 0.5f, 0.0f,
         -0.37f,0.07f, 0.0f,  1.0f, 0.5f, 0.0f,

         -0.43f,0.22f, 0.0f, 1.0f, 1.0f, 0.0f,
         -0.35f,0.18f, 0.0f,  1.0f, 1.0f, 0.0f,
         -0.25f,0.22f, 0.0f, 1.0f, 1.0f, 0.0f,

         -0.35f,0.18f, 0.0f,  1.0f, 0.5f, 0.0f,
         -0.25f,0.22f, 0.0f,  1.0f, 0.5f, 0.0f,
         -0.37f,0.07f, 0.0f,  1.0f, 0.5f, 0.0f,



         //cabello 

        0.12f,0.31f, 0.0f,  1.0f, 0.0f, 0.0f,
        0.2f,0.27f, 0.0f,   1.0f, 0.0f, 0.0f,
        0.37f,0.27f, 0.0f,  1.0f, 0.0f, 0.0f,

        0.12f,0.31f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.37f,0.27f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.4f,0.35f, 0.0f, 1.0f, 1.0f, 0.0f,

        0.28f,0.33f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.19f,0.39f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.4f,0.35f, 0.0f, 1.0f, 0.0f, 0.0f,

        0.19f,0.39f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.44f,0.44f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.4f,0.35f, 0.0f, 1.0f, 1.0f, 0.0f,

        0.3f,0.41f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.25f,0.47f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.44f,0.44f, 0.0f, 1.0f, 0.0f, 0.0f,

        0.44f,0.44f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.25f,0.47f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.5f,0.5f, 0.0f, 1.0f, 1.0f, 0.0f,

        0.42f,0.49f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.33f,0.57f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.5f,0.5f, 0.0f, 1.0f, 0.0f, 0.0f,

        0.5f,0.5f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.33f,0.57f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.57f,0.57f, 0.0f, 1.0f, 1.0f, 0.0f,

        0.51f,0.57f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.42f,0.65f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.57f,0.57f, 0.0f, 1.0f, 0.0f, 0.0f,

        0.57f,0.57f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.42f,0.65f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.66f,0.55f, 0.0f, 1.0f, 1.0f, 0.0f,

        //cuerpo

        -0.25f, 0.22f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.32f, 0.09f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.06f, 0.27f, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.32f, 0.09f, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.34f, -0.03f, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.25f, -0.1f, 0.0f, 0.5f, 1.0f, 1.0f,

        -0.32f, 0.09f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.25f, -0.1f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.12f, -0.03f, 0.0f, 0.0f, 1.0f, 1.0f,

        -0.25f, -0.1f, 0.0f, 0.0f, 0.5f, 1.0f,
        -0.18f, -0.12f, 0.0f, 0.0f, 0.5f, 1.0f,
        -0.12f, -0.03f, 0.0f, 0.0f, 0.5f, 1.0f,

        -0.32f, 0.09f, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.12f, 0.08f, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.12f, -0.03f, 0.0f, 0.5f, 1.0f, 1.0f,

        -0.32f, 0.09f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.06f, 0.27f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.12f, 0.08f, 0.0f, 0.0f, 1.0f, 1.0f,

        -0.12f, 0.08f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.06f, 0.27f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.07f, 0.08f, 0.0f, 0.0f, 1.0f, 1.0f,

        -0.12f, -0.03f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.12f, 0.08f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.07f, 0.08f, 0.0f, 0.0f, 1.0f, 1.0f,

        -0.12f, -0.03f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.07f, 0.08f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.08f, -0.04f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.07f, 0.08f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.06f, 0.27f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.09f, 0.25f, 0.0f, 1.0f, 1.0f, 1.0f,

        0.07f, 0.08f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.09f, 0.25f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.2f, 0.27f, 0.0f, 1.0f, 1.0f, 1.0f,

        0.08f, -0.04f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.07f, 0.08f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.23f, -0.07f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.07f, 0.08f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.24f, 0.1f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.23f, -0.07f, 0.0f, 0.0f, 0.5f, 1.0f,

        0.07f, 0.08f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.2f, 0.27f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.24f, 0.1f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.2f, 0.27f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.24f, 0.1f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.43f, 0.12f, 0.0f, 0.5f, 1.0f, 1.0f,

        0.23f, -0.07f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.24f, 0.1f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.43f, 0.12f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.23f, -0.07f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.43f, 0.12f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.41f, -0.04f, 0.0f, 0.0f, 0.5f, 1.0f,

        0.41f, -0.04f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.43f, 0.12f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.54f, -0.01f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.2f, 0.27f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.37f, 0.27f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.43f, 0.12f, 0.0f, 1.0f, 1.0f, 1.0f,

        0.37f, 0.27f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.51f, 0.24f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.43f, 0.12f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.43f, 0.12f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.51f, 0.24f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.58f, 0.2f, 0.0f, 0.0f, 0.5f, 1.0f,

        0.43f, 0.12f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.58f, 0.2f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.63f, 0.07f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.63f, 0.07f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.58f, 0.2f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.62f, 0.18f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.63f, 0.07f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.62f, 0.18f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.69f, 0.05f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.63f, 0.07f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.69f, 0.05f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.66f, 0.02f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.43f, 0.12f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.63f, 0.07f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.66f, 0.02f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.43f, 0.12f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.66f, 0.02f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.58f, -0.05f, 0.0f, 0.5f, 1.0f, 1.0f,

        // pata atras 1

        -0.31f, -0.16, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.34f, -0.03f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.25f, -0.1f, 0.0f, 0.0f, 1.0f, 1.0f,

        -0.37f, -0.22, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.25f, -0.1f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.18f, -0.12f, 0.0f, 0.0f, 1.0f, 1.0f,

        -0.43f, -0.18, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.25f, -0.1f, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.37f, -0.22, 0.0f, 0.5f, 1.0f, 1.0f,

        -0.42f, -0.23, 0.0f, 0.0f, 0.5f, 0.5f,
        -0.43f, -0.18, 0.0f, 0.0f, 0.5f, 0.5f,
        -0.37f, -0.22, 0.0f, 0.0f, 0.5f, 0.5f,

        -0.44f, -0.44, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.42f, -0.23, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.37f, -0.22, 0.0f, 0.5f, 1.0f, 1.0f,

        -0.44f, -0.44, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.37f, -0.22, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.4f, -0.44, 0.0f, 1.0f, 0.0f, 0.0f,

        -0.44f, -0.44, 0.0f, 1.0f, 0.5f, 0.0f,
        -0.4f, -0.44, 0.0f, 1.0f, 0.5f, 0.0f,
        -0.39f, -0.49, 0.0f, 1.0f, 0.5f, 0.0f,


        -0.46f, -0.52, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.43f, -0.47, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.4f, -0.52, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.43f, -0.47, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.39f, -0.49, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.4f, -0.52, 0.0f, 1.0f, 0.0f, 0.0f,

        -0.4f, -0.52, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.39f, -0.49, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.35f, -0.52, 0.0f, 1.0f, 0.0f, 0.0f,

        //PATA ATRAS 2

        -0.12f, -0.03f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.01f, -0.04f, 0.0f, 0.0f, 1.0f, 1.0f,
        -0.18f, -0.23f, 0.0f, 0.0f, 1.0f, 1.0f,

        -0.25f, -0.21f, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.12f, -0.03f, 0.0f, 0.5f, 1.0f, 1.0f,
        -0.18f, -0.23f, 0.0f, 0.5f, 1.0f, 1.0f,

        -0.25f, -0.21f, 0.0f, 0.0f, 0.5f, 0.5f,
        -0.18f, -0.23f, 0.0f, 0.0f, 0.5f, 0.5f,
        -0.23f, -0.26f, 0.0f, 0.0f, 0.5f, 0.5f,

        -0.23f, -0.26f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.18f, -0.23f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.15f, -0.4f, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.15f, -0.4f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.18f, -0.23f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.11f, -0.4f, 0.0f, 1.0f, 0.0f, 0.0f,

        -0.15f, -0.4f, 0.0f, 1.0f, 1.0f, 0.0f,
        -0.11f, -0.4f, 0.0f, 1.0f, 1.0f, 0.0f,
        -0.11f, -0.44f, 0.0f, 1.0f, 1.0f, 0.0f,

        -0.11f, -0.44f, 0.0f, 1.0f, 0.5f, 0.0f,
        -0.11f, -0.4f, 0.0f, 1.0f, 0.5f, 0.0f,
        -0.06f, -0.45f, 0.0f, 1.0f, 0.5f, 0.0f,

        -0.13f, -0.49f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.11f, -0.44f, 0.0f, 1.0f, 1.0f, 1.0f,
        -0.08f, -0.49f, 0.0f, 1.0f, 1.0f, 1.0f,

        -0.11f, -0.44f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.06f, -0.45f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.08f, -0.49f, 0.0f, 1.0f, 0.0f, 0.0f,

        -0.08f, -0.49f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.06f, -0.45f, 0.0f, 1.0f, 0.0f, 0.0f,
        -0.03f, -0.49f, 0.0f, 1.0f, 0.0f, 0.0f,

        //PATA DELANTE1

        0.58f, -0.05f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.66f, 0.02f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.73f, -0.01f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.58f, -0.05f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.73f, -0.01f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.75f, -0.05f, 0.0f, 0.0f, 0.5f, 1.0f,

        0.66f, 0.02f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.69f, 0.05f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.73f, -0.01f, 0.0f, 0.5f, 1.0f, 1.0f,

        0.73f, -0.01f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.75f, -0.05f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.83f, -0.02f, 0.0f, 1.0f, 1.0f, 1.0f,

        0.75f, -0.05f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.83f, -0.02f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.81f, -0.09f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.83f, -0.02f, 0.0f, 1.0f, 0.5f, 0.0f,
        0.81f, -0.09f, 0.0, 1.0f, 0.5f, 0.0f,
        0.87f, -0.12f, 0.0f, 1.0f, 0.5f, 0.0f,

        0.81f, -0.09f, 0.0, 1.0f, 0.5f, 0.0f,
        0.87f, -0.12f, 0.0f, 1.0f, 0.5f, 0.0f,
        0.84f, -0.15f, 0.0f, 1.0f, 0.5f, 0.0f,

        0.87f, -0.12f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.82f, -0.19f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.89f, -0.18f, 0.0f, 1.0f, 1.0f, 0.0f,

        0.8f, -0.2f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.87f, -0.26f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.89f, -0.18f, 0.0f, 1.0f, 0.0f, 0.0f,

        //pata adelante 2

        0.69f, 0.05f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.73f, -0.01f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.82f, 0.08f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.73f, -0.01f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.82f, 0.08f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.82f, 0.02f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.82f, 0.08f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.82f, 0.02f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.86f, 0.04f, 0.0f, 1.0f, 1.0f, 1.0f,

        0.82f, 0.02f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.86f, 0.04f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.88f, -0.01f, 0.0f, 1.0f, 0.0f, 0.0f,

        0.86f, 0.04f, 0.0f, 1.0f, 0.5f, 0.0f,
        0.91f, 0.0f, 0.0f, 1.0f, 0.5f, 0.0f,
        0.9f, -0.05f, 0.0f, 1.0f, 0.5f, 0.0f,

        0.89f, -0.1f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.91f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
        0.97f, -0.08f, 0.0f, 1.0f, 1.0f, 0.0f,

        0.89f, -0.1f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.97f, -0.08f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.97f, -0.16f, 0.0f, 1.0f, 0.0f, 0.0f,


        ////////CARA


        0.44f, 0.44f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.57f, 0.57f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.6f, 0.35f, 0.0f, 0.5f, 1.0f, 1.0f,

        0.44f, 0.44f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.37f, 0.27f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.6f, 0.35f, 0.0f, 0.5f, 1.0f, 1.0f,

        0.37f, 0.27f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.51f, 0.24f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.6f, 0.35f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.51f, 0.24f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.6f, 0.35f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.58f, 0.2f, 0.0f, 0.0f, 0.5f, 1.0f,

        0.58f, 0.2f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.6f, 0.35f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.62f, 0.18f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.57f, 0.57f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.66f, 0.55f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.66f, 0.51f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.57f, 0.57f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.6f, 0.4f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.66f, 0.51f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.66f, 0.55f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.66f, 0.51f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.74f, 0.59f, 0.0f, 1.0f, 1.0f, 1.0f,

        0.66f, 0.51f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.74f, 0.59f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.72f, 0.53f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.6f, 0.4f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.66f, 0.51f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.71f, 0.33f, 0.0f, 0.0f, 0.5f, 1.0f,

        0.66f, 0.51f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.72f, 0.53f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.75f, 0.45f, 0.0f, 0.5f, 1.0f, 1.0f,

        0.66f, 0.51f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.75f, 0.45f, 0.0f, 0.5f, 1.0f, 1.0f,
        0.71f, 0.33f, 0.0f, 0.5f, 1.0f, 1.0f,

        0.68f, 0.48f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.72f, 0.43f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.73f, 0.45f, 0.0f, 1.0f, 0.0f, 0.0f,

        0.71f, 0.33f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.75f, 0.45f, 0.0f, 0.0f, 1.0f, 1.0f,
        0.83f, 0.31f, 0.0f, 0.0f, 1.0f, 1.0f,

        0.6f, 0.4f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.6f, 0.35f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.7f, 0.29f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.6f, 0.4f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.71f, 0.33f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.7f, 0.29f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.7f, 0.29f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.71f, 0.33f, 0.0f, 0.0f, 0.5f, 0.5f,
        0.79f, 0.22f, 0.0f, 0.0f, 0.5f, 0.5f,

        0.79f, 0.22f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.71f, 0.33f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.82f, 0.24f, 0.0f, 0.0f, 0.5f, 1.0f,

        0.82f, 0.24f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.71f, 0.33f, 0.0f, 0.0f, 0.5f, 1.0f,
        0.83f, 0.31f, 0.0f, 0.0f, 0.5f, 1.0f,

    };

    int numTriangles = 350;

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glUseProgram(shaderProgram);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, numTriangles * 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}