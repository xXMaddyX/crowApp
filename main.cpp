//#define CROW_ENABLE_STATIC_DIR
//#define CROW_STATIC_DIRECTORY "./static/"

#include <iostream>
#include <crow.h>

int main() {
    crow::SimpleApp app;
    //app.add_static_dir();
    
    CROW_ROUTE(app, "/")([](crow::response& res){
        res.set_static_file_info("./static/index.html");
        res.end();
    });
    
    CROW_ROUTE(app, "/<path>")([](const crow::request& req, crow::response& res, std::string path) {
        std::string url = req.url;
        res.set_static_file_info("./static/" + url);
        res.end();
    });
    std::cout << "Crow App startet auf Port 3030..." << std::endl;
    app.port(3030).multithreaded().run();
    return 0;
}