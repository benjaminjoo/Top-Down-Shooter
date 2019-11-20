#pragma once

class Tile
{
private:

	bool connectedN = false;
	bool connectedS = false;
	bool connectedW = false;
	bool connectedE = false;

	bool visited	= false;

public:

	Tile();
	~Tile();

	void connectN() { connectedN	= true; }
	void connectS() { connectedS	= true; }
	void connectW() { connectedW	= true; }
	void connectE() { connectedE	= true; }

	void visit() { visited = true; }

	bool isConnectedN() { return connectedN; }
	bool isConnectedS() { return connectedS; }
	bool isConnectedW() { return connectedW; }
	bool isConnectedE() { return connectedE; }

	bool isVisited() { return visited; }
};

