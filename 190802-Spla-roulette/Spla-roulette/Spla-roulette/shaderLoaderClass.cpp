#include "stdafx.h"

#include "shaderLoaderClass.h"

#include <fstream>

shaderLoaderClass::shaderLoaderClass()
{
	printf("shaderLoaderClass init\n");
	printf("***CAUTION!! openGL should be set up before using this class!***\n");
}


shaderLoaderClass::~shaderLoaderClass()
{
}



bool shaderLoaderClass::loadShaderSource_And_CompileShader(const char* name, int type, GLuint* toObj)
{
	// C++ file
	std::ifstream sFile;

	// file open
	sFile.open(name);

	if (!sFile)
	{
		printf("%s can't be opened... return\n", name);
		return false;
	}

	// set file's position to end
	sFile.seekg(0, std::ios::end);


	// get file length
	unsigned long fLength = sFile.tellg();
	if (fLength == 0)
	{
		printf("this file contains nothing... return\n");
		sFile.close();
		return false;
	}
	else
	{
		printf("file length:%d\n", fLength);
	}


	// reset file position
	sFile.seekg(std::ios::beg);


	// create array for shader source
	GLchar* sourceArray = new char[fLength + 1];

	// set terminate zero
	sourceArray[fLength] = 0;


	// read source string
	int INDEX = 0;
	while (sFile.good())
	{
		sourceArray[INDEX] = sFile.get();

		if (!sFile.eof())
		{
			INDEX++;
		}
	}

	// set terminate zero
	sourceArray[INDEX] = 0;


	// close file
	sFile.close();



	// create shader object
	switch (type)
	{
	case 0: // vertex shader
		*toObj = glCreateShader(GL_VERTEX_SHADER);
		break;
	case 1:
		*toObj = glCreateShader(GL_GEOMETRY_SHADER);
		break;
	case 2:
		*toObj = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	default:
		printf("shader type should be 0, 1, or 2... return\n");
		return false;
		break;
	}


	// supply shader source to shader object
	glShaderSource(*toObj, 1, (const GLchar**)&sourceArray, NULL);

	// compile shader
	glCompileShader(*toObj);


	// error check
	GLint logLength;
	glGetShaderiv(*toObj, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 1)
	{
		GLchar* log = (GLchar*)malloc(logLength);
		glGetShaderInfoLog(*toObj, logLength, &logLength, log );
		printf("%s compile error %d :\n%s\n", name, logLength, log);
		free(log);
	}
	else
	{
		printf("%s compile success!\n", name);
	}


	// delete source array

	delete[] sourceArray;


	return true;
}




bool shaderLoaderClass::loadShaderSource_And_CompileShader_fromPtr(const char* stringPtr, int type, GLuint* toObj)
{



	// create shader object
	switch (type)
	{
	case 0: // vertex shader
		*toObj = glCreateShader(GL_VERTEX_SHADER);
		break;
	case 1:
		*toObj = glCreateShader(GL_GEOMETRY_SHADER);
		break;
	case 2:
		*toObj = glCreateShader(GL_FRAGMENT_SHADER);
		break;
	default:
		printf("shader type should be 0, 1, or 2... return\n");
		return false;
		break;
	}


	// supply shader source to shader object
	glShaderSource(*toObj, 1, (const GLchar**)&stringPtr, NULL);

	// compile shader
	glCompileShader(*toObj);


	// error check
	GLint logLength;
	glGetShaderiv(*toObj, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 1)
	{
		GLchar* log = (GLchar*)malloc(logLength);
		glGetShaderInfoLog(*toObj, logLength, &logLength, log);
		printf("[Shader %d from ptr] compile error %d :\n%s\n", type, logLength, log);
		free(log);
	}
	else
	{
		printf("[Shader %d from ptr] compile success!\n", type);
	}



	return true;
}



bool shaderLoaderClass::createProgram_And_AttachShader(GLuint* prgPtr, GLuint* vsPtr, GLuint* gsPtr, GLuint* fsPtr)
{
	// create program object
	*prgPtr = glCreateProgram();

	// attach shader
	if (vsPtr != NULL)
	{
		glAttachShader( *prgPtr, *vsPtr ); 
	}
	if (gsPtr != NULL)
	{
		glAttachShader( *prgPtr, *gsPtr);
	}
	if (fsPtr != NULL)
	{
		glAttachShader(*prgPtr, *fsPtr);
	}


	// link program
	glLinkProgram( *prgPtr );


	// check status
	GLint status;
	glGetProgramiv(*prgPtr, GL_LINK_STATUS, &status);
	if (status == GL_TRUE)
	{
		printf("program object link success!\n");
	}
	else
	{
		printf("program object link error.... return %d\n", status);
		return false;
	}


	return true;
}

void shaderLoaderClass::getUniformLocation(GLuint* prgObj, GLint* uniform, const char* name)
{
	*uniform = glGetUniformLocation(*prgObj, name);
	printf("PRG:%d, %s, %d\n", *prgObj, name, *uniform);

}

