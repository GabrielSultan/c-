#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

struct Question {
    std::string text;
    std::string options[4];
    char correctOption;
};

void displayQuestion(const Question& q) {
    std::cout << q.text << std::endl;
    
    for (char i = 'A'; i <= 'D'; ++i) {
        std::cout << i << ") " << q.options[i - 'A'] << std::endl;
    }
}

void shuffleQuestions(std::vector<Question>& questions) {
    std::srand(std::time(0));
    
    std::random_shuffle(questions.begin(), questions.end());
}

int main() {
    std::vector<Question> questions = {
        {"Who wrote 'Pride and Prejudice'?",   {"Charles Dickens", "Jane Austen", "Emily Brontë", "Mark Twain"}, 'B'},
        {"What is the name of the protagonist in  'To Kill a Mockingbird'?", {"Scout Finch", "Atticus Finch", "Boo Radley", "Tom Robinson"}, 'A'},
        {"Which poet wrote 'The Road Not Taken'?",  {  "Robert Frost", "Walt Whitman", "Emily Dickinson", "T.S.  Eliot"}, 'A'},
        {"Who is the tragic hero in Shakespeare's 'Hamlet'?", {"Claudius", "Hamlet", "Ophelia", "Polonius"}, 'B'},
        {"What is a metaphor?", {"A direct comparison using 'like' or 'as'", "A figure of speech that describes an object by asserting it is something else", "A repetition of consonant sounds", "A figure of speech that asks a question to produce an dramatic effect"}, 'B'},
        {"Who is the author of 'Moby-Dick'?", {"Herman Melville", "Nathaniel Hawthorne", "Edgar Allan Poe", "Henry David Thoreau"}, 'A'},
        {"What is the title of George Orwell's dystopian novel?", {"Brave New World", "1984", "Fahrenheit 451", "The Handmaid's Tale"}, 'B'},
        {"Which poet wrote 'Because I could not stop for Death'?", {"Robert Frost", "Emily Dickinson", "Walt Whitman", "Sylvia Plath"}, 'B'},
        {"Who wrote the play 'Death of a Salesman'?", {"Tennessee Williams", "Arthur Miller", "Eugene O'Neill", "Samuel Beckett"}, 'B'},
          {"What is an oxymoron?", {"A figure of speech that combines contradictory terms", "A repetition of words at the beginning of lines", "A comparison using 'like' or 'as'", "A figure of speech that asks a question"}, 'A'},
        {"In 'The Great Gatsby,' what is the name of the valley of ashes?", {"West Egg", "East Egg", "Valley of Ashes", "New York City"}, 'C'},
        {"Who is the author of 'The Catcher in the Rye'?", {"J.D. Salinger",
        
        "Harper Lee", "Ernest Hemingway", "F. Scott Fitzgerald"}, 'A'},
        {"Which poet wrote 'The Waste Land'?", {"T.S. Eliot", "Ezra Pound", "William Butler Yeats", "Langston Hughes"}, 'A'},
        {"What is the name of the protagonist in Shakespeare's 'Othello'?", {"Iago", "Desdemona", "Othello", "Cassio"}, 'C'},
        {"What is alliteration?", {"The repetition of consonant sounds at the beginning of words", "A figure of speech that asks a question", "A comparison using 'like' or 'as'", "A figure of speech that combines contradictory terms"}, 'A'},
        {"Who wrote 'Wuthering Heights'?", {"Charlotte Brontë", "Emily Brontë", "Jane Austen", "Charles Dickens"}, 'B'},
        {"What is the title of Harper Lee's famous novel?", {"To Kill a Mockingbird", "The Grapes of Wrath", "The Sun Also Rises", "The Old Man and the Sea"}, 'A'},
        {"Which poet wrote 'Leaves of Grass'?", {"Walt Whitman", "Emily Dickinson", "Robert Frost", "Langston Hughes"}, 'A'},
        {"Who wrote the play 'A Streetcar Named Desire'?", {"Tennessee Williams", "Arthur Miller", "Eugene O'Neill", "Samuel Beckett"}, 'A'},
        {"What is a simile?", {"A direct comparison using 'like' or 'as'", "A figure of speech that combines contradictory terms", "A repetition of consonant sounds", "A figure of speech that asks a question"}, 'A'},
        {"What is the name of the creature in Mary Shelley's 'Frankenstein'?", {"Dr. Frankenstein", "The Creature", "Igor", "Elizabeth"}, 'B'},
        {"Who is the author of 'One Hundred Years of Solitude'?", {"Gabriel García Márquez", "Jorge Luis Borges", "Isabel Allende", "Pablo Neruda"}, 'A'},
        {"Which poet wrote 'The Raven'?", {"Edgar Allan Poe", "Robert Frost", "Walt Whitman", "Emily Dickinson"}, 'A'},
        {"Who wrote the play 'Waiting for Godot'?", {"Samuel Beckett", "Tennessee Williams", "Arthur Miller", "Eugene O'Neill"}, 'A'},
        {"What is onomatopoeia?", {"A word that imitates the sound it describes", "A figure of speech that asks a question", "A comparison using 'like' or 'as'", "A repetition of consonant sounds"}, 'A'},
        {"Who wrote 'Jane Eyre'?", {"Charlotte Brontë", "Emily Brontë", "Jane Austen", "Charles Dickens"}, 'A'},
        {"What is the title of Ernest Hemingway's novel about a fisherman?", {"The Old Man and the Sea", "The Sun Also Rises", "A Farewell to Arms", "For Whom the Bell Tolls"}, 'A'},
        {"Which poet wrote 'The Love Song of J. Alfred Prufrock'?", {"T.S. Eliot", "Ezra Pound", "William Butler Yeats", "Langston Hughes"}, 'A'},
        {"Who wrote the play 'The Crucible'?", {"Arthur Miller", "Tennessee Williams", "Eugene O'Neill", "Samuel Beckett"}, 'A'},
          {"Who wrote 'War and Peace'?", {"Leo tolstoy", "Fyodor Dostoevsky", "Anton Chekhov", "Alexander Pushkin"}, 'A'},
        {"What is the title of Aldous Huxley's dystopian novel?", {"Brave New World", "1984", "Fahrenheit 451", "The Handmaid's Tale"}, 'A'},
         {"Which poet wrote 'Do not go gentle into that good night'?", {"Dylan Thomas", "Robert Frost", "Walt Whitman", "Sylvia Plath"}, 'A'},
        {"Who wrote the play 'The Importance of Being Earnest'?", {"Oscar Wilde", "George Bernard Shaw", "Henrik Ibsen", "Samuel Beckett"}, 'A'},
        {"What is hyperbole?", {"A  figure of spech that uses exaggeration for emphasis", "A repetition of consonant sounds", "A comparison using 'like' or 'as'", "A figure of speech that combines contradictory terms"}, 'A'},
        {"In 'The Adventures of Huckleberry Finn,' who is Huck's friend who is a runaway slave?", {"Tom Sawyer", "Jim", "Becky Thatcher", "Pap Finn"}, 'B'},
          {"Who is the author of 'The Bell Jar'?", {"Sylvia Plath", "Virginia Woolf", "Toni Morrison", "Margaret Atwood"}, 'A'},
        {"Which poet wrote 'She Walks in Beauty'?", {"Lord Byron", "John Keats", "Percy Bysshe Shelley", "William Wordsworth"}, 'A'},
        {"Who wrote the play 'A Raisin in the Sun'?", {"Lorraine Hansberry", "August Wilson", "Arthur Miller", "Tennessee Williams"}, 'A'},
        {"What is personification?", {"A figure of speech that gives human qualities to non-human things", "A repetition of consonant sounds", "A comparison using 'like' or 'as'", "A figure of speech that combines contradictory terms"}, 'A'},
        {"Who wrote 'Dracula'?", {"Bram Stoker", "Mary Shelley", "H.G. Wells", "Robert Louis Stevenson"}, 'A'},
        {"What is the title of Ralph Ellison's novel about an invisible man?", {"Invisible Man", "Native Son", "The Bluest Eye", "Beloved"}, 'A'},
        {"Which poet wrote  'Annabel Lee'?", {"Edgar Allan Poe", "Robert Frost", "Walt Whitman", "Emily Dickinson"}, 'A'},
          {"Who wrote the play 'Fences'?", {"August Wilson", "Lorraine Hansberry", "Arthur Miller", "Tennessee Williams"}, 'A'},
        {"What is irony?",  {"A figure of speech that expresses something contrary to what is expected", "A repetition of consonant sounds", "A comparison using 'like' or  'as'",
        "A figure of speech that combines contradictory terms"}, 'A'},
        {"Who wrote 'The Count of Monte Cristo'?", {"Alexandre Dumas", "Victor Hugo", "Honoré de Balzac", "Gustave Flaubert"}, 'A'},
        {"Who is the author of 'Things Fall Apart'?", {"Chinua Achebe", "Wole Soyinka", "Ngũgĩ wa Thiong'o", "Nadine Gordimer"}, 'A'},
        {"Which poet wrote 'The Tyger'?", {"William Blake", "John Keats", "Percy Bysshe Shelley", "William Wordsworth"}, 'A'},
        {"Who wrote the play  'Long Day's Journey into Night'?", {"Eugene O'Neill", "Tennessee William", "Arthur Miller", "Samuel Beckett"}, 'A'},
        {"What is a pun?",   {"A form of word play that uses a word or phrase with two meaning", "A  repetition of consonant sounds", "A comparison using 'like' or 'as'", "A figure of speech that combines contradictory terms"}, 'A'}
    };

    shuffleQuestions(questions);

    int totalQuestions = questions.size();
    int numQuestions;

    std::cout << "WELCOME TO THE  LITERATURE QUIZ !" << std::endl << std::endl;
    std::cout << "It is a multiple choice quiz, you can answer by A, B, C or D, don't forget to put the answer in capital letters !" << std::endl << std::endl;
    std::cout << "How many questions would you like to answer? (1-" << totalQuestions << "): ";
    std::cin >> numQuestions;

    if (numQuestions < 1 || numQuestions > totalQuestions) {
        std::cout << "Invalid number of questions. Defaulting to " << totalQuestions << " questions." << std::endl;
        numQuestions = totalQuestions;
    }

    int score = 0;
    char userAnswer;

    
    for  (int i = 0; i < numQuestions; ++i) {
        displayQuestion(questions[i]);
        std::cout << " Your answer (A, B, C, or D): ";
        std::cin >> userAnswer;

        if (userAnswer == questions[i].correctOption) {
            ++score;
        }
    }

    
    double passMark =   0.6 * numQuestions;
    std::cout << "Your score  : " << score << "/" << numQuestions << std::endl;
    
    
    if (score >=   passMark) {
        std::cout << "Congratulations You passed the quiz." << std::endl;
    } else {
        std::cout << "Sorry, you did not pass the quiz. " << std::endl;
    }

    return  0;
}
