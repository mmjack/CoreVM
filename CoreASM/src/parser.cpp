#include "parser.h"
#include <stdio.h>

using namespace Assembler;

Parser::Parser() {}
Parser::~Parser() {}

void Parser::parse(char const* input, ByteBuffer& buffer) {
	Token next = Token(INVALID_TOKEN);
	do {
		next = _tokeniser.nextToken(input);
		printf("Token %i (%s)\n", next.tokenId(), next.tokenString() ? next.tokenString() : "");
	} while (next.tokenId() != INVALID_TOKEN && next.tokenId() != TOKEN_EOF);
}
