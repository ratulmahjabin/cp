import pygame
import random
pygame.init()

white = (255,255,255)  #'Generating colour'
black = (0,0,0,0)
red= (255,0,0)
green = (47, 181, 52)
custom = (120,175,10)
yellow = (255,25,98)

#Game Variables---------------------------------------------------------------------------------------------------------
display_width =800
display_height =600

sound = pygame.mixer.Sound("nom.wav")


gameDisplay = pygame.display.set_mode((display_width,display_height))   #for displaying the surface(w,h)
pygame.display.set_caption("A+ Snake")   #'caption of the game'
icon = pygame.image.load("c.png")
pygame.display.set_icon(icon)

img = pygame.image.load('d.png')
apple = pygame.image.load('c.png')


FPS = 18
direction = "right"
block_size = 20
AppleThickness = 30
clock = pygame.time.Clock()
smallfont = pygame.font.SysFont("comicsansms", 25)
medfont = pygame.font.SysFont("comicsansms", 50)	#Font generating
largefont = pygame.font.SysFont("comicsansms", 75)


#Functions--------------------------------------------------------------------------------------------------------------

def paused():
    pause = True
    while pause:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_c:
                    pause = False

                elif event.key == pygame.K_q:
                    pygame.quit()
                    quit()

        gameDisplay.fill(white)
        message_to_screen("pause", green,-100,size="large")
        message_to_screen("press c to continue or Q to quit",black ,25,size="small")

        pygame.display.update()
        clock.tick(5)


def score(score):
    text = smallfont.render("Score: "+ str(score) , True , black)
    gameDisplay.blit(text, [0,0])


def text_obj(text, clr , size):
    global textSurface
    if size == "small":
        textSurface = smallfont.render(text , True, clr)

    elif size == "medium":
        textSurface = medfont.render(text , True, clr)

    elif size == "large":
        textSurface = largefont.render(text, True, clr)

    return textSurface , textSurface.get_rect()

def message_to_screen(msg, clr , y_displace=0, size= "small"):
    textSurf , textRect = text_obj(msg ,clr , size)
    textRect.center = (display_width/2),(display_height/2)+ y_displace
    gameDisplay.blit(textSurf , textRect)


    # screen_text = font.render(msg,True,clr)
    # gameDisplay.blit(screen_text, [display_width/4,display_height/4])


def snake(block_size , snakeList):
    if direction == "right":
        head = pygame.transform.rotate(img, 270)
    if direction == "left":
        head = pygame.transform.rotate(img, 90)
    if direction == "up":
        head = pygame.transform.rotate(img, 0)
    if direction == "down":
        head = pygame.transform.rotate(img, 180)
    gameDisplay.blit(head , (snakeList[-1][0], snakeList[-1][1]))

    for XnY in snakeList[ :-1]:
        pygame.draw.rect(gameDisplay, custom, [XnY[0],XnY[1],block_size, block_size])

def appleDraw(apple, randAppleX , randAppleY):
    gameDisplay.blit(apple ,(randAppleX ,randAppleY))

def game_intro():
    intro = True
    while intro:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_c:
                    intro = False
                if event.key == pygame.K_q:
                    pygame.quit()
                    quit()

        gameDisplay.fill(white)
        message_to_screen("Welcome to A+ Land", green, -100, "large")
        message_to_screen("Created by Ratul Mahjabin" , black , -10)
        message_to_screen("Objective: The more A+ you get , The more educated you will be xD", black, 20)
        message_to_screen("Don't dare to think out of the box! You will lose", custom, 50 )
        message_to_screen("To play press C or P to pause and to quit press Q.", yellow, 150)
        pygame.display.update()
        clock.tick(15)
def randAplusGen():
    randAppleX = round(random.randrange(0, display_width - AppleThickness))
    randAppleY = round(random.randrange(0, display_height - AppleThickness))

    return randAppleX,randAppleY




#gameLoop---------------------------------------------------------------------------------------------------------------
def gameloop():

    global direction
    gameExit = False  # gameExit value
    gameOver = False
    lead_x = display_width/2  # Head of snake and x,y values are the co-ordinate
    lead_y = display_height/2
    lead_x_change = 10
    lead_y_change = 0
    snakeList = []
    snakeLength = 1

    randAppleX, randAppleY = randAplusGen()
    while not gameExit:


        while gameOver == True:
            gameDisplay.fill(white)
            message_to_screen("Game Over" , red, -40 ,size="large")
            message_to_screen("Press C to play again and Q to quit", black , 50 ,size="medium")
            pygame.display.update()
 # Event Handling--------------------------------------------------------------------------------------------------------
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    gameExit = True
                    gameOver = False
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_q:
                        gameExit = True
                        gameOver = False
                    if event.key == pygame.K_c:
                        gameloop()


        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                gameExit = True     #Game End

            if event.type == pygame.KEYDOWN:    #Key pressing
                if event.key == pygame.K_LEFT:
                    direction = "left"
                    lead_x_change = -block_size #Lessen lead_x by 10 bcz our head box's w=10,h=10
                    lead_y_change = 0
                elif event.key == pygame.K_RIGHT:
                    direction = "right"
                    lead_x_change = block_size
                    lead_y_change = 0
                elif event.key == pygame.K_UP:
                    direction = "up"
                    lead_y_change = -block_size
                    lead_x_change = 0
                elif event.key == pygame.K_DOWN:
                    direction = "down"
                    lead_x_change = 0
                    lead_y_change = block_size
                elif event.key == pygame.K_p:
                    paused()
#Logic Handlng---------------------------------------------------------------------------------------------------------
        lead_x += lead_x_change
        lead_y += lead_y_change

        if lead_x>=display_width or lead_x<0 or lead_y>=display_height or lead_y<0:
            gameOver = True

        gameDisplay.fill((120, 160, 198  ))
        # pygame.draw.rect(gameDisplay, red, [lead_x,lead_y,10,10]) #rect(display,colour, [x,y,width,hieght])
        appleDraw(apple, randAppleX, randAppleY)#drawing apple

        snake_Head = []
        snake_Head.append(lead_x)
        snake_Head.append(lead_y)
        snakeList.append(snake_Head)
        if len(snakeList) > snakeLength:
            del snakeList[0]
        for eachSegment in snakeList[:-1]:
            if eachSegment == snake_Head:
                gameOver = True
        score(snakeLength-1)
        snake(block_size ,snakeList)
        pygame.display.update()


        # if lead_x >= randAppleX and lead_x <= randAppleX + AppleThickness:
        #     if lead_y >= randAppleY and lead_y <= randAppleY + AppleThickness:
        #         randAppleX = round(random.randrange(0, display_width - block_size))
        #         randAppleY = round(random.randrange(0, display_height - block_size))
        #         snakeLength+=1

        if lead_x > randAppleX and lead_x < randAppleX + AppleThickness or lead_x + block_size > randAppleX and lead_x + block_size < randAppleX + AppleThickness:
           if lead_y > randAppleY and lead_y < randAppleY + AppleThickness or lead_y + block_size > randAppleY and lead_y + block_size < randAppleY + AppleThickness:
                randAppleX, randAppleY = randAplusGen()
                pygame.mixer.Sound.play(sound)
                snakeLength+=1


#-------------------------------------------------------------------------------------------------------------------------

        clock.tick(FPS)



    pygame.quit()
    quit()

game_intro()
gameloop()
