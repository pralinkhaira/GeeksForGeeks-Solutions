class Solution:
    def __init__(self):
        self.document = ""
        self.undo_stack = []
        self.redo_stack = []
    
    def append(self, x: str):
        # Save current state before appending
        self.undo_stack.append(self.document)
        # Clear redo stack when new append is done
        self.redo_stack = []
        # Append character
        self.document += x
    
    def undo(self):
        # If there's something to undo
        if self.undo_stack:
            # Save current state to redo stack
            self.redo_stack.append(self.document)
            # Restore previous state
            self.document = self.undo_stack.pop()
    
    def redo(self):
        # If there's something to redo
        if self.redo_stack:
            # Save current state to undo stack
            self.undo_stack.append(self.document)
            # Restore next state
            self.document = self.redo_stack.pop()
    
    def read(self):
        # Return current document content
        return self.document