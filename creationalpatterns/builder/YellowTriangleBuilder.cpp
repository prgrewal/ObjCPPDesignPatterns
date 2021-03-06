#include "TriangleBuilder.hpp"

class YellowTriangleBuilder : public TriangleBuilder {
public:
    void buildVertexShader() {
        const char* vertexShader = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
        
        this->triangle->setVertexShader(vertexShader);
    }
    void buildFragmentShader() {
        const char *fragmentShader = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
        "}\n\0";
        
        this->triangle->setFragmentShader(fragmentShader);
    }
    void setTriangle() {
        this->triangle = new Triangle();
    }
    void buildVertices() {
        float secondTriangle[] = {
            0.0f, -0.75f, 0.0f,  // left
            0.45f, -0.5f, 0.0f,  // right
            0.45f, 0.25f, 0.0f   // top
        };
        vector<float> secondTriangleVector(secondTriangle, secondTriangle + (sizeof(secondTriangle) / sizeof(secondTriangle[0])));
        this->triangle->setVertices(secondTriangleVector);
    }
    void getTriangle() {
        glUseProgram(this->triangle->shaderProgram);
        glBindVertexArray(this->triangle->VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    void compileShaders() {
        this->triangle->compileVertexShader();
        this->triangle->compileFragmentShader();
    }
    void buildLinkProgram() {
        this->triangle->linkProgram();
        this->triangle->deleteShaders();
    }
    void buildVertexArrayObject() {
        this->triangle->generateVertexArrayObject();
    }
    ~YellowTriangleBuilder() {
        delete this->triangle;
    }
};
