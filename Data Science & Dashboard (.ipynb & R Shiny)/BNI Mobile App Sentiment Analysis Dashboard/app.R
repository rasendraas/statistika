library(shiny)
library(bs4Dash)
library(dplyr)
library(readr)
library(plotly)
library(leaflet)
library(DT)
library(fresh)
library(wordcloud2)

plot_colour <- "#3DC0BA"

theme <- create_theme(
  bs4dash_color(
    lime = "#FF8601",
    olive = "#E1EF5C",
    purple = "#E1EF5C"
  ),
  bs4dash_status(
    primary = "#E1EDED",
    info = "#E4E4E4"
  )
)


# Load and wrangle data ---------------------------------------------

data_mb <- read.csv("www/ulasan_per_tanggal_MB_6bln.csv")

content_1_mb <- data_mb[data_mb$score == 1, c("at", "score", "content")]
content_2_mb <- data_mb[data_mb$score == 2, c("at", "score", "content")]
content_3_mb <- data_mb[data_mb$score == 3, c("at", "score", "content")]
content_4_mb <- data_mb[data_mb$score == 4, c("at", "score", "content")]
content_5_mb <- data_mb[data_mb$score == 5, c("at", "score", "content")]

data_w <- read.csv("www/ulasan_per_tanggal_W_6bln.csv")

content_1_w <- data_w[data_w$score == 1, c("at", "score", "content")]
content_2_w <- data_w[data_w$score == 2, c("at", "score", "content")]
content_3_w <- data_w[data_w$score == 3, c("at", "score", "content")]
content_4_w <- data_w[data_w$score == 4, c("at", "score", "content")]
content_5_w <- data_w[data_w$score == 5, c("at", "score", "content")]

# User Interface ----------------------------------------------------------

ui <- dashboardPage(
  
  title = "Mobile Banking App Sentiment",
  
  freshTheme = theme,
  dark = NULL,
  help = NULL,
  scrollToTop = TRUE,
  
  # Header ----
  header = dashboardHeader(
    status = "lime",
    title = dashboardBrand(
  title = tags$span(
    HTML('<span style="color: #014150;">BNI App</span> <b style="color: #014150;">Dashboard</b>')
  ),
      color = "olive",
      image = "https://www.kindpng.com/picc/m/403-4035673_bni-logo-bank-negara-indonesia-hd-png-download.png"
    ),
    controlbarIcon = icon("circle-info"),
    fixed = TRUE
  ),
  # Sidebar ----
  sidebar = dashboardSidebar(
    sidebarMenu(
      id = "sidebarMenuid",
      menuItem(
        "Home",
        tabName = "home",
        icon = icon("home")
      ),
      menuItem(
        "Analysis",
        tabName = "dashboard",
        icon = icon("bar-chart")
      )
    )
  ),
  
  dashboardControlbar(
    box(
      title = "Dashboard Developer",
      width = 12,
      img(src = "FOTO PAS PUTIH.png", height = "150px", style = "width: auto;"),
      p(tags$b("Rasendra A. Satyatama"), style = "margin-bottom: 0;"),  # Nama tebal
      p("Statistika - ITS Surabaya", style = "margin-top: 0; margin-bottom: 0;")
    ),
    box(
      title = "Sentiment Analyst",
      width = 12,
      img(src = "FOTO PAS PUTIH Ibel Si Wondr.png", height = "150px", style = "width: auto;"),
      p(tags$b("M. Iqbal Nurrifki"), style = "margin-bottom: 0;"),  # Nama tebal
      p("Statistika - ITS Surabaya", style = "margin-top: 0; margin-bottom: 0;")
    ),
    box(
      title = "Users Analyst",
      width = 12,
      img(src = "Brian.png", height = "150px", style = "width: auto;"),
      p(tags$b("Brian Arga Prasidio Putra"), style = "margin-bottom: 0;"),  # Nama tebal
      p("Teknik Sistem & Industri - ITS Surabaya", style = "margin-top: 0; margin-bottom: 0;")
    )
  ),
  # Footer ----
  footer = dashboardFooter(
    left = "Practical Work - 5003221061 - 5003221120",
    right = "Statistika ITS - 2025"
  ),
  
  # Body ----
  body = dashboardBody(
    tabItems(
      
      # Home tab ----
      tabItem(
        tabName = "home",
        
        jumbotron(
          title = tags$div(
            "BNI Mobile Banking App Sentiment Analysis",
            style = "font-weight: bold;
             background: linear-gradient(to right, #099596, #014150); 
             -webkit-background-clip: text; 
             color: transparent;"
          ),
          status = "info",
          lead = "Analyzing the comparison of sentiments between BNI Mobile Banking and its latest version, Wondr by BNI over the last 6 months (July 5, 2024, to January 9, 2025).",
          "BNI is gradually transitioning from BNI Mobile Banking to the superapp Wondr by BNI, launched on July 5, 2024, and already encompassing 90% of the features from the previous application. This transition is expected to be completed within 6–12 months to ensure ease of transactions for customers. This move is part of BNI's transformation to deliver more innovative and optimal digital banking services.",
          btnName = NULL,
          style = "background: linear-gradient(to right, #014150, #099596); 
           padding: 20px; 
           border-radius: 10px; 
           color: white;"
        ),
        
        fluidRow(
          
          userBox(
            collapsible = FALSE,
            title = NULL,
            div(
              tags$img(
                src = "UI Wondr.png",
                style = "width: 100%; height: auto; border-radius: 0; margin-bottom: 10px;"
              ),
              h4("Wondr by BNI", style = "margin-top: 10px; text-align: center;"),
              h5("User Interface", style = "text-align: center;font-weight: lighter;")
            )
          ),
          
          box(
            title = "What is the difference between BNI Mobile Banking and Wondr?",
            width = 6,
            collapsible = FALSE,
            tags$iframe(
              src = "https://www.youtube.com/embed/PsbWb_ljIGQ",
              width = "100%",
              height = "435",
              frameborder = "2",
              allow = "accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture",
              allowfullscreen = TRUE
            )
          ),
          box(
            title = "Wondr users from july until october 2024",
            width = 6,
            collapsible = FALSE,
            tags$img(
              src = "Wondr BNI Users.png",
              style = "width: 100%; height: auto; border-radius: 0; margin-bottom: 10px;"
            )
          ),
          box(
            collapsible = FALSE,
            tags$img(
              src = "BNI.png",
              style = "width: 105%; height: auto; border-radius: 0; margin-bottom: 10px;"
            )
          )
        )
        
      ),
      
      # Dashboard tab ----
      tabItem(
        tabName = "dashboard",
        
        ## Info boxes ----
        tags$h4("BNI Mobile Banking Sentiment Ratio (8497 Reviews over last 6 months until 2025-01-09)", style = "text-align: center; font-weight: medium; margin-bottom: 10px;"),
        fluidRow(
          column(
            width = 4,
            tags$div(
              class = "info-box",
              style = "background-color: #f0f0f0; padding: 10px; border-radius: 5px;",
              tags$div(
                style = "display: flex; align-items: center; justify-content: space-between;", # Flexbox alignment
                tags$img(src = "angry.png", height = "50px", width = "50px", style = "margin-right: 10px;"), # Image
                tags$div(
                  style = "font-size: 30px; font-weight: bold; display: flex; align-items: center;",
                  "29.19%",
                  tags$span(style = "font-size: 20px; font-weight: normal; margin-left: 10px;", "[Negative]") # Label
                )
              )
            )
          ),
          
          column(
            width = 4,
            tags$div(
              class = "info-box",
              style = "background-color: #f0f0f0; padding: 10px; border-radius: 5px;",
              tags$div(
                style = "display: flex; align-items: center;",
                tags$img(src = "neutral 1.png", height = "50px", width = "50px", style = "margin-right: 10px;"),
                tags$div(
                  style = "font-size: 30px; font-weight: bold;",
                  "38.58%",
                  tags$span(style = "font-size: 20px; font-weight: normal; margin-left: 10px;", "[Neutral]")
                )
              )
            )
          ),
          
          column(
            width = 4,
            tags$div(
              class = "info-box",
              style = "background-color: #f0f0f0; padding: 10px; border-radius: 5px;",
              tags$div(
                style = "display: flex; align-items: center;",
                tags$img(src = "laughing.png", height = "50px", width = "50px", style = "margin-right: 10px;"),
                tags$div(
                  style = "font-size: 30px; font-weight: bold;",
                  "32.23%",
                  tags$span(style = "font-size: 20px; font-weight: normal; margin-left: 10px;", "[Positive]")
                )
              )
            )
          )
        ),
        tags$h4("Wondr Sentiment Ratio (17108 Reviews over last 6 months until 2025-01-09)", style = "text-align: center; font-weight: medium; margin-bottom: 10px;"),
        fluidRow(
          column(
            width = 4,
            tags$div(
              class = "info-box",
              style = "background-color: #f0f0f0; padding: 10px; border-radius: 5px;",
              tags$div(
                style = "display: flex; align-items: center; justify-content: space-between;", # Flexbox alignment
                tags$img(src = "angry.png", height = "50px", width = "50px", style = "margin-right: 10px;"), # Image
                tags$div(
                  style = "font-size: 30px; font-weight: bold; display: flex; align-items: center;",
                  "23%",
                  tags$span(style = "font-size: 20px; font-weight: normal; margin-left: 10px;", "[Negative]") # Label
                )
              )
            )
          ),
          
          column(
            width = 4,
            tags$div(
              class = "info-box",
              style = "background-color: #f0f0f0; padding: 10px; border-radius: 5px;",
              tags$div(
                style = "display: flex; align-items: center;",
                tags$img(src = "neutral 1.png", height = "50px", width = "50px", style = "margin-right: 10px;"),
                tags$div(
                  style = "font-size: 30px; font-weight: bold; display: flex; align-items: center;",
                  "44.94%",
                  tags$span(style = "font-size: 20px; font-weight: normal; margin-left: 10px;", "[Neutral]")
                )
              )
            )
          ),
          
          column(
            width = 4,
            tags$div(
              class = "info-box",
              style = "background-color: #f0f0f0; padding: 10px; border-radius: 5px;",
              tags$div(
                style = "display: flex; align-items: center;",
                tags$img(src = "laughing.png", height = "50px", width = "50px", style = "margin-right: 10px;"),
                tags$div(
                  style = "font-size: 30px; font-weight: bold; display: flex; align-items: center;",
                  "32.06%",
                  tags$span(style = "font-size: 20px; font-weight: normal; margin-left: 10px;", "[Positive]")
                )
              )
            )
          )
        ),
        
        ## Sortable boxes ----
        fluidRow(
          sortable(
            width = 6,
            
            box(
              title = "Ratings Distribution (1–5 Stars) for BNI Mobile Banking (Last 6 Months)", 
              width = 12, 
              status = "olive",
              collapsible = FALSE,
              plotlyOutput("plot_ratings_count")
            ),
            
            box(
              title = "Word Cloud for BNI Mobile Banking [Negative/Neutral/Positive]",
              width = 12, 
              status = "olive",
              collapsible = TRUE, 
              sidebar = boxSidebar(
                id = "boxsidebarid",
                selectInput(
                  inputId = "sentiment1",
                  label = "Select Sentiment",
                  choices = c("Negative", "Neutral", "Positive"),
                  selected = "Negative",
                  width = "100%"
                )
              ),
              uiOutput("wordcloud_image1")
            )
          ),
          
          sortable(
            width = 6,
            
            box(
              title = "Ratings Distribution (1–5 Stars) for Wondr (Last 6 Months)",
              width = 12,  
              status = "olive",
              ribbon(
                text = "Wondr",
                color = "olive"
              ),
              plotlyOutput("plot_ratings_count_2")
            ),
            
            box(
              title = "Word Cloud for Wondr [Negative/Neutral/Positive]",
              width = 12, 
              status = "olive",
              collapsible = TRUE, 
              ribbon(
                text = "Wondr",
                color = "olive"
              ),
              
              sidebar = boxSidebar(
                id = "boxsidebarid",
                selectInput(
                  inputId = "sentiment",
                  label = "Select Sentiment",
                  choices = c("Negative", "Neutral", "Positive"),
                  selected = "Negative",
                  width = "100%"
                )
              ),
              uiOutput("wordcloud_image")
            )
          )
        ),
        titlePanel("Most Liked Reviews for Wondr (Last 6 Months)"),
        tabBox(
          title = "Data",
          width = 12,
          type = "tabs",
          status = "olive",
          solidHeader = TRUE,
          
          tabPanel(
            "1-star rating",
            DTOutput("useful_table_1")
          ),
          tabPanel(
            "2-star rating",
            DTOutput("useful_table_2")
          ),
          tabPanel(
            "3-star rating",
            DTOutput("useful_table_3")
          ),
          tabPanel(
            "4-star rating",
            DTOutput("useful_table_4")
          ),
          tabPanel(
            "5-star rating",
            DTOutput("useful_table_5")
          )
        ),
        titlePanel("Raw Data Reviews from Google Play Store (Last 6 Months)"),
        # Dropdown for selecting score
        selectInput("rate", "Select Rate:", choices = c("All", 1, 2, 3, 4, 5), selected = "All"),
        ## Tab box ----
        tabBox(
          title = "Data",
          width = 12,
          type = "tabs",
          status = "olive",
          solidHeader = TRUE,
          
          tabPanel(
            "BNI Mobile Banking",
            DTOutput("sentiment_table")
          ),
          tabPanel(
            "Wondr by BNI",
            DTOutput("sentiment_table_w")
          )
        )
      )
    )
  )
)


# Server ------------------------------------------------------------------

server <- function(input, output) {
  
  output$plot_ratings_count <- renderPlotly({
    
    # Baca data dari folder www
    datarmb <- read.csv("www/rating_MB_6bln.csv")
    
    # Hitung jumlah skor dan urutkan sumbu y berdasarkan nilai score
    datarmb %>% 
      count(score) %>% 
      mutate(score = factor(score, levels = sort(unique(score), decreasing = TRUE))) %>% 
      plot_ly(
        x = ~n,
        y = ~score,
        type = "bar",
        marker = list(color = plot_colour),
        orientation = "h"
      ) %>% 
      layout(
        xaxis = list(title = "Count"),
        yaxis = list(
          title = "",
          tickfont = list(size = 14, weight = "bold") # Memperbesar dan menebalkan teks sumbu y
        ),
        title = "Count Plot of Ratings"
      ) %>% 
      config(displayModeBar = FALSE)
  })
  
  # Sightings by location
  output$plot_ratings_count_2 <- renderPlotly({
    
    # Baca data dari folder www
    datarw <- read.csv("www/rating_W_6bln.csv")
    
    # Hitung jumlah skor dan urutkan sumbu y berdasarkan nilai score
    datarw %>% 
      count(score) %>% 
      mutate(score = factor(score, levels = sort(unique(score), decreasing = TRUE))) %>% 
      plot_ly(
        x = ~n,
        y = ~score,
        type = "bar",
        marker = list(color = plot_colour),
        orientation = "h"
      ) %>% 
      layout(
        xaxis = list(title = "Count"),
        yaxis = list(
          title = "",
          tickfont = list(size = 14, weight = "bold") # Memperbesar dan menebalkan teks sumbu y
        ),
        title = "Count Plot of Ratings"
      ) %>% 
      config(displayModeBar = FALSE)
  })
  
  output$wordcloud_image <- renderUI({
    img_src <- switch(input$sentiment,
                      "Negative" = "W Negative 6bln.png",
                      "Neutral" = "W Neutral 6bln.png",
                      "Positive" = "W Positive 6bln.png")
    tags$img(src = img_src, width = "100%")
  })
  
  output$wordcloud_image1 <- renderUI({
    img_src <- switch(input$sentiment1,
                      "Negative" = "MB Negative 6bln.png",
                      "Neutral" = "MB Neutral 6bln.png",
                      "Positive" = "MB Positive 6bln.png")
    tags$img(src = img_src, width = "100%")
  })
  
  filtered_data <- reactive({
    if (input$rate == "All") {
      data_mb
    } else {
      switch(as.character(input$rate),
             "1" = content_1_mb,
             "2" = content_2_mb,
             "3" = content_3_mb,
             "4" = content_4_mb,
             "5" = content_5_mb)
    }
  })
  
  output$sentiment_table <- renderDT({
    datatable(filtered_data(), options = list(pageLength = 5))
  })
  
  filtered_data_w <- reactive({
    if (input$rate == "All") {
      data_w
    } else {
      switch(as.character(input$rate),
             "1" = content_1_w,
             "2" = content_2_w,
             "3" = content_3_w,
             "4" = content_4_w,
             "5" = content_5_w)
    }
  })
  
  output$sentiment_table_w <- renderDT({
    datatable(filtered_data_w(), options = list(pageLength = 5))
  })
  
  data_r1 <- read.csv("www/top_10_ratingWondr_1.csv")
  colnames(data_r1) <- c("Comment", "Rating", "Likes", "Date")
  
  data_r2 <- read.csv("www/top_10_ratingWondr_2.csv")
  colnames(data_r2) <- c("Comment", "Rating", "Likes", "Date")
  
  data_r3 <- read.csv("www/top_10_ratingWondr_3.csv")
  colnames(data_r3) <- c("Comment", "Rating", "Likes", "Date")
  
  data_r4 <- read.csv("www/top_10_ratingWondr_4.csv")
  colnames(data_r4) <- c("Comment", "Rating", "Likes", "Date")
  
  data_r5 <- read.csv("www/top_10_ratingWondr_5.csv")
  colnames(data_r5) <- c("Comment", "Rating", "Likes", "Date")
  
  output$useful_table_1 <- renderDT({
    datatable(data_r1, options = list(pageLength = 5))
  })
  output$useful_table_2 <- renderDT({
    datatable(data_r2, options = list(pageLength = 5))
  })
  output$useful_table_3 <- renderDT({
    datatable(data_r3, options = list(pageLength = 5))
  })
  output$useful_table_4 <- renderDT({
    datatable(data_r4, options = list(pageLength = 5))
  })
  output$useful_table_5 <- renderDT({
    datatable(data_r5, options = list(pageLength = 5))
  })
  
}

shinyApp(ui, server)