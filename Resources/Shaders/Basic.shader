#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;
layout (location = 3) in vec3 aTexCoord;
layout (location = 3) in vec3 aNormal;

uniform mat4 modelTransformMatrix; // Model to world
uniform mat4 viewMatrix; // World to view
uniform mat4 projectionMatrix; // View to projection
uniform mat3 normalMatrix;

out vec4 vertexColor;
out vec3 normal;
out vec3 fragPos;

void main()
{
    vec4 worldPos = modelTransformMatrix * vec4(aPos, 1.0);
    gl_Position = projectionMatrix * viewMatrix * worldPos;
    vertexColor = color;
    normal = normalMatrix * aNormal;
    fragPos = vec3(modelTransformMatrix * vec4(aPos, 1.0));
};

#shader fragment
#version 330 core
in vec4 vertexColor;
in vec3 normal;
in vec3 fragPos;

uniform vec4 lightingColor;
uniform vec3 lightPos;
uniform vec3 cameraPos;

out vec4 FragColor;

void main()
{
    float ambientStr = 0.1;
    float specStr = .5;
    vec4 ambient = ambientStr * lightingColor;

    vec3 norm = normalize(normal);

    vec3 lightDir = normalize(lightPos - fragPos);
    vec3 viewDir = normalize(cameraPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float diff = max(dot(norm, lightDir), 0.0);
    vec4 diffuse = diff * lightingColor;
    
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
    vec4 specular = specStr * spec * lightingColor;

    //FragColor = vertexColor * ambient;
    FragColor = (ambient + diffuse + specular) * vertexColor;
    //FragColor = vec4(normal * 0.5 + 0.5, 1.0);
}