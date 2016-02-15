class Document:
    """A Basic Document Class for New Holland Press."""

    def __init__(self, title, wordage):
        self.title = title
        self.wordage = wordage

    def readDocument(self):
        return self.wordage