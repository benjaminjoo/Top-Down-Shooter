#pragma once

#include <memory>

#include "Canvas.h"


struct record
{
	int content = 0;
	std::shared_ptr<record> left_child	= nullptr;
	std::shared_ptr<record> right_child = nullptr;
};


class Tree
{
private:

	std::shared_ptr<Canvas> Screen;

	int			rootPosition;
	int			spacingH;
	int			fontSize;
	int			border;
	int			maxWidth;
	int			maxDepth;
	Uint32		text_colour;

	std::shared_ptr<record> rootNode;
	
	void send2Tree(const int& a, std::shared_ptr<record> node);

	void traverseTree(const int& level, const int& position, std::shared_ptr<record> node);

	void drawNode(const record& node, const int& level, const int& xPos);

protected:

public:

	Tree(std::shared_ptr<Canvas> S, const int& rootContent);
	~Tree();

	void add2Tree(const int& a);

	void drawTree();

	

};


Tree::Tree(std::shared_ptr<Canvas> S, const int& rootContent)
{
	Screen = S;

	spacingH = 64;

	fontSize = 8;

	border = 4;

	maxWidth = 1024;

	maxDepth = Screen->getHeight() / spacingH - 1;

	rootPosition = (int)((double)Screen->getWidth() * 0.5f);

	text_colour = argbColour(0, 255, 255, 255);

	rootNode = std::make_shared<record>();
	rootNode->content = rootContent;
	rootNode->left_child = nullptr;
	rootNode->right_child = nullptr;
}


Tree::~Tree()
{

}


void Tree::send2Tree(const int& a, std::shared_ptr<record> node)
{
	if (a > node->content)
	{
		if (node->right_child == nullptr)
		{
			node->right_child = std::make_shared<record>();
			node->right_child->content = a;
			node->right_child->left_child = nullptr;
			node->right_child->right_child = nullptr;
		}
		else
		{
			this->send2Tree(a, node->right_child);
		}
	}
	else if (a < node->content)
	{
		if (node->left_child == nullptr)
		{
			node->left_child = std::make_shared<record>();
			node->left_child->content = a;
			node->left_child->left_child = nullptr;
			node->left_child->right_child = nullptr;
		}
		else
		{
			this->send2Tree(a, node->left_child);
		}
	}
}


void Tree::add2Tree(const int& a)
{
	this->send2Tree(a, rootNode);
}


void Tree::drawNode(const record& node, const int& level, const int& xPos)
{
	int yPos = (level + 1) * spacingH;

	Screen->displayInt(node.content, fontSize, xPos, yPos, text_colour, true, border);

	if (node.left_child != nullptr)
	{
		int shift = (int)((double)maxWidth * 0.25f / (double)power(2, level));

		int top, bottom, left, right, centre;
		top = yPos + (int)((double)fontSize * 0.5f) + border;
		bottom = yPos + spacingH - (int)((double)fontSize * 0.5f) - border;
		left = xPos - shift;
		right = xPos - (int)((double)fontSize * 0.5f);
		centre = yPos + (int)((double)spacingH * 0.5f);

		Screen->drawLine(screenCoord(right, top), screenCoord(right, centre), text_colour);
		Screen->drawLine(screenCoord(right, centre), screenCoord(left, centre), text_colour);
		Screen->drawLine(screenCoord(left, centre), screenCoord(left, bottom), text_colour);
	}
	if (node.right_child != nullptr)
	{
		int shift = (int)((double)maxWidth * 0.25f / (double)power(2, level));

		int top, bottom, left, right, centre;
		top = yPos + (int)((double)fontSize * 0.5f) + border;
		bottom = yPos + spacingH - (int)((double)fontSize * 0.5f) - border;
		right = xPos + shift;
		left = xPos + (int)((double)fontSize * 0.5f);
		centre = yPos + (int)((double)spacingH * 0.5f);

		Screen->drawLine(screenCoord(left, top), screenCoord(left, centre), text_colour);
		Screen->drawLine(screenCoord(left, centre), screenCoord(right, centre), text_colour);
		Screen->drawLine(screenCoord(right, centre), screenCoord(right, bottom), text_colour);
	}
}


void Tree::drawTree()
{
	this->traverseTree(0, rootPosition, rootNode);
}


void Tree::traverseTree(const int& level, const int& position, std::shared_ptr<record> node)
{
	this->drawNode(*node, level, position);
	if (node->left_child != nullptr)
	{
		int next_level = level + 1;
		if (next_level <= maxDepth)
		{
			int shift = (int)((double)maxWidth * 0.25f / (double)power(2, level));
			int next_position = position - shift;
			this->traverseTree(next_level, next_position, node->left_child);
		}	
	}
	if (node->right_child != nullptr)
	{
		int next_level = level + 1;
		if (next_level <= maxDepth)
		{
			int shift = (int)((double)maxWidth * 0.25f / (double)power(2, level));
			int next_position = position + shift;
			this->traverseTree(next_level, next_position, node->right_child);
		}		
	}
}



